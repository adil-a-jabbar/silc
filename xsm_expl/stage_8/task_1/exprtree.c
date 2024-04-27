#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "exprtree.h"
#include "symbolTable.h"
#include "typetable.h"
#include "classtable.h"
#include "functionChecks.h"

struct tnode * makeLeafNode (int nodeType, char *val, struct Typetable * type){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    if (type == intType || type == nullType) temp->val = atoi(val);
    else if (type == strType){
        temp->strVal = (char*)malloc(sizeof(val));
        strcpy (temp->strVal, val);
    }
    temp->left = NULL;
    temp->right = NULL;
    temp->type = type;
    return temp;
}

struct tnode * makeIdNode (int nodeType, char* varName){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->varName = (char*)malloc(strlen(varName)+1);
    strcpy (temp->varName, varName);
    temp->left = NULL;
    temp->right = NULL;
    temp->Gentry = NULL;
    return temp;
}

struct tnode * makeOperatorNode (int nodeType, char op, struct tnode * left, struct tnode * right){
    //typechecking
    if (nodeType == OP && ((left->type != intType) | (right->type != intType))) {
        yyerror("type error !\n");
    }
    else if (nodeType == BOOL && (left->type != right->type && right->type != nullType)) {
        yyerror("type error !\n");
    }
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    if (nodeType == OP) temp->type = intType;
    else if (nodeType == BOOL) temp->type = boolType;
    temp->op = op;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode * makeStmtNode (int nodeType, struct tnode * left, struct tnode * right, struct tnode * mid){
    //typechecking
    if (right != NULL && nodeType==ASG_STMT){
        if (right->Ctype != NULL){
            if (left->Ctype == NULL) {
                char msg[60];
                sprintf(msg, "\ntype error\n");
                yyerror(msg);
            }
            if (checkInheritance (left->Ctype, right->Ctype)) {
                char msg[60];
                sprintf(msg, "\ncannot assign var of class '%s' to class '%s'\n", left->Ctype->name, right->Ctype->name);
                yyerror(msg);
            }
            left->Ctype = right->Ctype;
        }
        if (right->type != left->type) {
            char msg[60];
            sprintf(msg, "\ntype error\n");
            yyerror(msg);
        }
        right->type = left->type;
    }

    if (nodeType == FREE_STMT){
        if (right->type == intType || right->type == strType || right->type == boolType) {
            char msg[40];
            sprintf(msg, "\ncannot free '%s'\n", right->varName);
            yyerror(msg);
        }
    }

    if (nodeType == OUTPUT_STMT){
        if (left->Ctype == NULL && (left->type != intType && left->type != strType && left->type != nullType)) {
            char msg[40];
            sprintf(msg, "\ncannot write for type: '%s'\n", typeToString(left->type));
            yyerror(msg);
        }
    }

    if (nodeType == INPUT_STMT){
        if (left->type != intType && left->type != strType) {
            char msg[40];
            sprintf(msg, "\ncannot read for type: '%s'\n", typeToString(left->type));
            yyerror(msg);
        }
    }

    if (nodeType == IFNODE || nodeType == IFELSE) {
        if (left->type != boolType){
            char msg[40];
            sprintf(msg, "\ntype error!\n");
            yyerror(msg);
        }
    }


    // if ((nodeType == ASG_STMT && (right->type!=NULL && left->type!=NULL && right->type != nullType && left->type != right->type)) | (nodeType == ASG_STMT && (left->nodeType != IDENT && left->nodeType != FIELD_NODE) )){
    //     printf ("ltype: %s, rtype %s\n", left->type->name, right->type->name);
    //     yyerror("\ntype error !\n");
    // }
    // else if ((((nodeType == IFNODE) | (nodeType == IFELSE)) && (left->type != boolType))){
    //     yyerror("\ntype error !\n");
    // }
    // else if (nodeType == INPUT_STMT && left->nodeType != IDENT && left->nodeType != FIELD_NODE) {
    //     yyerror("\ntype error !\n");
    // }

    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = left;
    temp->right = right;
    if (nodeType == IFELSE){
        temp->mid = mid;
    }
    if (nodeType == ASG_STMT){
        temp->op = '=';
    }
    return temp;
}

struct tnode * makeConnectorNode (int nodeType, struct tnode * left, struct tnode * right){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode *makeTreeNode (int nodeType, struct Typetable * type, int val, char *strVal, char op, char *varName, struct Gsymbol *Gentry, struct tnode *left,struct tnode *right,struct tnode *mid){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = left;
    temp->right = right;
    temp->mid = mid;
    temp->val = val;
    if (varName != NULL){
        temp->varName = (char*)malloc(sizeof(varName));
        strcpy (temp->varName, varName);
    }
    return temp;
}

struct tnode * makeFieldNode (int nodeType, struct tnode * left, struct tnode * right){
    if ((FLookup (left->type, right->varName)) == NULL && Class_FLookup (left->Ctype, right->varName) == NULL){
        char msg[100];
        if (left->type != NULL)
        sprintf (msg, "'%s' does not have a member named '%s'\n", left->type->name, right->varName);
        else
        sprintf (msg, "'%s' does not have a member named '%s'\n", left->Ctype->name, right->varName);
        yyerror (msg);
    }
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = left;
    temp->right = right;
    return temp;
}

struct tnode * makeAllocNode (int nodeType, struct Classtable * class){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = NULL;
    temp->right = NULL;
    if (class != NULL){
        temp->Ctype = class;
    }
    if (temp->nodeType == INITIALIZE_NODE){
        temp->type = intType;
    }
    return temp;
}

struct tnode * makeSelfNode (int nodeType, char *varName) {
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->varName = (char*)malloc(strlen(varName)+1);
    strcpy (temp->varName, varName);
    temp->left = NULL;
    temp->right = NULL;
    temp->type = NULL;
    temp->Ctype = CLookup (currClass);
    return temp;
}

struct tnode * makeCFunCallNode (int nodeType, struct tnode *left, struct tnode *mid, struct tnode *right) {
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    temp->left = left;
    temp->right = right;
    temp->mid = mid;
    struct Memberfunclist *tempMember = Class_MLookup (left->Ctype, right->varName);
    if (tempMember == NULL) {
            char msg[40];
            sprintf(msg, "\n%s does not have method '%s'\n", left->Ctype->name, right->varName);
            yyerror(msg);
    }
    methodArgsCheck (tempMember, argsHead[argsTop]);
    argsHead[argsTop] = NULL;
    argsTail[argsTop] = NULL;
    right->type = tempMember->type;
    right->Ctype = tempMember->Ctype;
    temp->type = right->type;
    temp->Ctype = right->Ctype;
    return temp;
}

int getReg (){
    if (currReg != 20)
    currReg ++;
    return currReg-1;
}

void freeReg(){
    if (currReg != 0)
    currReg --;
}

void headerGen (FILE * filePointer){
    fprintf (filePointer, "0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\nMOV SP, 4197\n");
    Initialize (filePointer);
    fprintf (filePointer, "CALL VFTGEN\n");
    fprintf (filePointer, "PUSH R0 //retVal for main\nCALL MAIN\n");
}

void Initialize (FILE * filePointer){
    fprintf (filePointer, "MOV R0, \"Heapset\"\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
}

//codegen for VFT entry  for all classes
void VFTGen (FILE * filePointer) {
    fprintf (filePointer, "VFTGEN:\n");
    struct Classtable * temp = Chead;
    while (temp != NULL){
        //add label for each method
        int address = getAddress (8); //allocate 8 words for class' VFT in stack
        struct Memberfunclist * method = temp->Vfuncptr;
        while (method != NULL){
            fprintf (filePointer, "MOV [%d], F%d\n", address++, method->Flabel); 
            method = method->next;
        }
        temp = temp->next;
    }
    fprintf (filePointer, "RET\n");
}

void exitGen (FILE * filePointer){
    int currReg = getReg ();
    fprintf (filePointer, "MOV R%d, \"Exit\"\nPUSH R%d\nPUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\nCALL 0\n", currReg, currReg);
}

void push_label (int label) {
    top ++;
    label_stack [top] = label;
}

int pop_label () {
    if (top != -1)
    top --;
    return label_stack [top+1];
}

int getLabel (){
    currLabel ++;
    return currLabel-1;
}

int getFlabel (){
    currFlabel ++;
    return currFlabel-1;
}

int isEmpty (){
    if (top == -1) return 1;
    else return 0;
}

int codeGen (struct tnode *t, FILE * filePointer){
    printf ("codegen for type: %d\n", t->nodeType);
    if (t->nodeType == CONNECTOR){
        printf ("connector node\n");
        codeGen (t->left, filePointer);
        codeGen (t->right, filePointer);
        return -1;
    }

    else if (t->nodeType == FUN_DEF){
        printf ("fun def node (%s)\n", currGSymbol->name);
        int flabel = currGSymbol->flabel;
        fprintf (filePointer, "F%d:\n", flabel);
        fprintf (filePointer, "PUSH BP //save old BP\n"); //save old BP
        fprintf (filePointer, "MOV BP, SP //set new BP\n");  //set new BP
        struct Lsymbol * temp = Lhead;
        while (temp != NULL){
            if (temp->binding>0)
            fprintf (filePointer, "PUSH R0 //push space for loc var\n"); //push space for local variables
            temp = temp->next;
        }
        codeGen (t->left, filePointer);
        int tempReg = getReg ();
        temp = Lhead;
        while (temp != NULL){   //POP out local variables
            if (temp->binding>0)
            fprintf (filePointer, "POP R%d //pop loc var\n", tempReg); 
            temp = temp->next;
        }
        fprintf (filePointer, "MOV BP, [BP]\nPOP R0 //reset BP\n"); //reset BP
        fprintf (filePointer, "RET\n");
        freeReg ();
        freeReg ();
        return -1;
    }

    else if (t->nodeType == C_FUN_DEF){
        printf ("fun def node (%s)\n", currMethod);
        int flabel = (Class_MLookup (CLookup (currClass), currMethod))->Flabel;
        fprintf (filePointer, "F%d:\n", flabel);
        fprintf (filePointer, "PUSH BP //save old BP\n"); //save old BP
        fprintf (filePointer, "MOV BP, SP //set new BP\n");  //set new BP
        struct Lsymbol * temp = Lhead;
        while (temp != NULL){
            if (temp->binding>0)
            fprintf (filePointer, "PUSH R0 //push space for loc var\n"); //push space for local variables
            temp = temp->next;
        }
        codeGen (t->left, filePointer);
        int tempReg = getReg ();
        temp = Lhead;
        while (temp != NULL){   //POP out local variables
            if (temp->binding>0)
            fprintf (filePointer, "POP R%d //pop loc var\n", tempReg); 
            temp = temp->next;
        }
        fprintf (filePointer, "MOV BP, [BP]\nPOP R0 //reset BP\n"); //reset BP
        fprintf (filePointer, "RET\n");
        freeReg ();
        freeReg ();
        return -1;
    }

    else if (t->nodeType == MAIN_FUN){
        printf ("main fun node\n");
        fprintf (filePointer, "MAIN:\n");
        fprintf (filePointer, "PUSH BP //set new BP\n");  //save BP
        fprintf (filePointer, "MOV BP, SP //set new BP\n");  //set new BP
        struct Lsymbol * temp = Lhead;
        while (temp != NULL){
            if (temp->binding>0)
            fprintf (filePointer, "PUSH R0 //space for loc var\n"); //push space for local variables
            temp = temp->next;
        }
        codeGen (t->left, filePointer);
        codeGen (t->right, filePointer);
    }

    else if (t->nodeType == FUN_CALL){
        printf ("fun call node (%s)\n", t->Gentry->name);
        int tempReg;
        for (int i=0; i<currReg; i++){      //push all registers in use
            fprintf (filePointer, "PUSH R%d //push reg in use\n", i);
        }
        regUseStack [++regUseStackTop] = currReg;
        if (t->mid != NULL){    //push arguments
            struct tnode * temp = t->mid;
            while (temp != NULL){
                tempReg = codeGen (temp, filePointer);
                if (temp->nodeType == IDENT || temp->nodeType == FIELD_NODE)
                fprintf (filePointer, "MOV R%d, [R%d]\n", tempReg, tempReg);
                fprintf (filePointer, "PUSH R%d //pushing argument\n", tempReg);
                freeReg ();
                temp=temp->mid;
            }
        }
        fprintf (filePointer, "PUSH R0 //retVal\n"); //space for return value
        fprintf (filePointer, "CALL F%d\n", t->Gentry->flabel); //call statement
        int resultReg = getReg ();
        tempReg = getReg ();
        fprintf (filePointer, "POP R%d //store result\n", resultReg);  //store result in result register
        if (t->mid != NULL){    //pop arguments
            struct tnode * temp = t->mid;
            while (temp != NULL){
                fprintf (filePointer, "POP R%d //pop argument\n", tempReg);
                temp=temp->mid;
            }
        }
        freeReg ();
        for (int i=regUseStack [regUseStackTop--]-1; i>-1; i--){      //restore registers in use
            fprintf (filePointer, "POP R%d //restore reg in use\n", i);
        }
        return resultReg;
    }

    else if (t->nodeType == C_FUN_CALL){
        printf ("fun call node (%s)\n", t->right->varName);
        //check if method exist
        printf ("t->left->varname is: %s\n", t->left->varName);
        struct Memberfunclist * temp = Class_MLookup (t->left->Ctype, t->right->varName);
        if (temp == NULL) {
            char msg[40];
            sprintf(msg, "\n%s does not have method '%s'\n", t->left->Ctype->name, t->right->varName);
            yyerror(msg);
        }
        int tempReg;
        for (int i=0; i<currReg; i++){      //push all registers in use
            fprintf (filePointer, "PUSH R%d //push reg in use\n", i);
        }
        regUseStack [++regUseStackTop] = currReg;
        tempReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "MOV R%d, [R%d]\n", tempReg, tempReg);  
        fprintf (filePointer, "PUSH R%d //self\n", tempReg);    //push self
        freeReg ();
        if (t->mid != NULL){    //push arguments
            struct tnode * temp = t->mid;
            while (temp != NULL){
                tempReg = codeGen (temp, filePointer);
                if (temp->nodeType == IDENT || temp->nodeType == FIELD_NODE)
                fprintf (filePointer, "MOV R%d, [R%d]\n", tempReg, tempReg);
                fprintf (filePointer, "PUSH R%d //pushing argument\n", tempReg);
                freeReg ();
                temp=temp->mid;
            }
        }
        fprintf (filePointer, "PUSH R0 //retVal\n"); //space for return value
        int varReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "ADD R%d, 1\n", varReg);
        fprintf (filePointer, "MOV R%d, [R%d]\n", varReg, varReg);
        fprintf (filePointer, "ADD R%d, %d\n", varReg, Class_MLookup(t->left->Ctype, t->right->varName)->Funcposition);
        fprintf (filePointer, "MOV R%d, [R%d]\n", varReg, varReg);
        fprintf (filePointer, "CALL R%d\n", varReg); //call statement
        freeReg ();
        int resultReg = getReg ();
        tempReg = getReg ();
        fprintf (filePointer, "POP R%d //store result\n", resultReg);  //store result in result register
        if (t->mid != NULL){    //pop arguments
            struct tnode * temp = t->mid;
            while (temp != NULL){
                fprintf (filePointer, "POP R%d //pop argument\n", tempReg);
                temp=temp->mid;
            }
        }
        fprintf (filePointer, "POP R%d //pop self\n", tempReg);
        freeReg ();
        for (int i=regUseStack [regUseStackTop--]-1; i>-1; i--){      //restore registers in use
            fprintf (filePointer, "POP R%d //restore reg in use\n", i);
        }
        return resultReg;
    }

    else if (t->nodeType == RET_STMT){
        printf ("ret node\n");
        int resultReg = codeGen (t->left, filePointer);
        if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
        fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg, resultReg);
        int tempReg = getReg();
        fprintf (filePointer, "MOV R%d, BP\n", tempReg);
        fprintf (filePointer, "SUB R%d, 2\n", tempReg);
        fprintf (filePointer, "MOV [R%d], R%d\n", tempReg, resultReg);
        freeReg();
        return resultReg;
    }

    else if (t->nodeType == OP){
        printf ("op node (%c)\n", t->op);
        if (t->op == '+'){
            int resultReg1, resultReg2;
            resultReg1 = codeGen (t->left, filePointer);
            if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg1, resultReg1);
            resultReg2 = codeGen (t->right, filePointer);
            if (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg2, resultReg2);

            fprintf (filePointer, "ADD R%d, R%d\n", resultReg1, resultReg2);
            freeReg();
            return resultReg1;
        }

        else if (t->op == '-'){
            int resultReg1, resultReg2;
            resultReg1 = codeGen (t->left, filePointer);
            if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg1, resultReg1);
            resultReg2 = codeGen (t->right, filePointer);
            if (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg2, resultReg2);
            
            fprintf (filePointer, "SUB R%d, R%d\n", resultReg1, resultReg2);
            freeReg();
            return resultReg1;
        }

        else if (t->op == '*'){
            int resultReg1, resultReg2;
            resultReg1 = codeGen (t->left, filePointer);
            if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg1, resultReg1);
            resultReg2 = codeGen (t->right, filePointer);
            if (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg2, resultReg2);
            
            fprintf (filePointer, "MUL R%d, R%d\n", resultReg1, resultReg2);
            freeReg();
            return resultReg1;
        }

        else if (t->op == '/'){
            int resultReg1, resultReg2;
            resultReg1 = codeGen (t->left, filePointer);
            if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg1, resultReg1);
            resultReg2 = codeGen (t->right, filePointer);
            if (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg2, resultReg2);
            
            fprintf (filePointer, "DIV R%d, R%d\n", resultReg1, resultReg2);
            freeReg();
            return resultReg1;
        }

        else if (t->op == '%'){
            int currReg = getReg ();
            int resultReg1, resultReg2;
            resultReg1 = codeGen (t->left, filePointer);
            if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg1, resultReg1);
            resultReg2 = codeGen (t->right, filePointer);
            if (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg2, resultReg2);

            fprintf (filePointer, "MOV R%d, R%d\n", currReg, resultReg1);
            fprintf (filePointer, "DIV R%d, R%d\n", resultReg1, resultReg2);
            fprintf (filePointer, "MUL R%d, R%d\n", resultReg2, resultReg1);
            fprintf (filePointer, "SUB R%d, R%d\n", currReg, resultReg2);
            freeReg();
            freeReg();
            return currReg;
        }
    }

    else if (t->nodeType == INPUT_STMT){
        printf ("read node\n");
        int currReg = getReg();
        fprintf (filePointer, "MOV R%d, \"Read\"\nPUSH R%d\n", currReg, currReg);
        fprintf (filePointer, "MOV R%d, \"-1\"\nPUSH R%d\n", currReg, currReg);
            
        int resultReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "PUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", resultReg);
        freeReg ();

        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg();
        return 0;
    }

    else if (t->nodeType == OUTPUT_STMT){
        printf ("write node\n");
        int resultReg;
        int currReg = getReg();
        fprintf (filePointer, "MOV R%d, \"Write\"\nPUSH R%d\n", currReg, currReg);
        fprintf (filePointer, "MOV R%d, \"-2\"\nPUSH R%d\n", currReg, currReg);
        resultReg = codeGen (t->left, filePointer);
        if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
        fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg, resultReg);

        fprintf (filePointer, "PUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", resultReg);
        freeReg ();
        
        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg();
        return 0;
    }

    else if (t->nodeType == ASG_STMT){
        printf ("assg node\n");
        int resultRegRight = codeGen (t->right, filePointer);
        int rightvftReg = getReg();
        if (t->left->Ctype != NULL && (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)) {   //if operand is class, store vft
            fprintf (filePointer, "MOV R%d, R%d\n", rightvftReg, resultRegRight);
            fprintf (filePointer, "ADD R%d, 1 //right VFT\n", rightvftReg);
        }

        if (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)
        fprintf (filePointer, "MOV R%d, [R%d]\n", resultRegRight, resultRegRight);
        
        int tempReg = codeGen (t->left, filePointer);

        if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
        fprintf (filePointer, "MOV [R%d], R%d\n", tempReg, resultRegRight);

        if (t->left->Ctype != NULL && (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)) {   //if operand is class, also copy vft location
            fprintf (filePointer, "ADD R%d, 1\n", tempReg);
            fprintf (filePointer, "MOV [R%d], [R%d]\n", tempReg, rightvftReg);
        }

        if (t->left->Ctype != NULL && t->right->nodeType == ALLOC_NODE) {   //new object allocation -> set vft 
            int vftBase = 4096 + 8*(t->right->Ctype->Class_index);
            fprintf (filePointer, "ADD R%d, 1\n", tempReg);
            fprintf (filePointer, "MOV [R%d], %d //set VFT\n", tempReg, vftBase);
        }

        freeReg ();
        freeReg ();
        freeReg ();
        return 0;
    }

    else if (t->nodeType == ALLOC_NODE){
        int resultReg = getReg();
        int currReg = getReg();
        if (t->type != NULL)
        fprintf (filePointer, "BRKP\nMOV R%d, \"Alloc\"\nPUSH R%d\nMOV R%d, %d\nPUSH R%d\n", currReg, currReg, currReg, t->type->size, currReg);
        else
        fprintf (filePointer, "BRKP\nMOV R%d, \"Alloc\"\nPUSH R%d\nMOV R%d, %d\nPUSH R%d\n", currReg, currReg, currReg, 8, currReg);
        fprintf (filePointer, "PUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\n", currReg, currReg, currReg);
        fprintf (filePointer, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", resultReg, currReg, currReg, currReg, currReg);
        freeReg();
        return resultReg;
    }

    else if (t->nodeType == INITIALIZE_NODE){
        int resultReg = getReg();
        int currReg = getReg();
        fprintf (filePointer, "MOV R%d, \"Heapset\"\nPUSH R%d\nPUSH R%d\n", currReg, currReg, currReg);
        fprintf (filePointer, "PUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0\n", currReg, currReg, currReg);
        fprintf (filePointer, "POP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n", resultReg, currReg, currReg, currReg, currReg);
        freeReg();
        return resultReg;
    }


    else if (t->nodeType == FREE_STMT) {
        int currReg = codeGen (t->right, filePointer);
        int tempReg = getReg();
        fprintf (filePointer, "MOV R%d, \"Free\"\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nPUSH R%d\nCALL 0", tempReg, tempReg, currReg, tempReg, tempReg, tempReg);
        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg();
        freeReg();
        return -1;
    }

    else if (t->nodeType == CONST){
        printf ("const node (%d)\n", t->val);
        int resultReg = getReg();
        if (t->type == intType || t->type == nullType)
        fprintf (filePointer, "MOV R%d, %d\n", resultReg, t->val);
        else if (t->type == strType)
        fprintf (filePointer, "MOV R%d, %s\n", resultReg, t->strVal);
        return resultReg;
    }

    else if (t->nodeType == IDENT){
        printf ("ident node ()\n");
        int resultReg;
        if (t->left == NULL){
            resultReg = getReg();
            struct Lsymbol * Lentry = LSymbolLookup(t->varName);
            if (Lentry != NULL){
                int binding = Lentry->binding;
                if (binding < 0){ //parameter
                    int temp = ((abs(currNBinding)-abs(binding))+2);
                    binding = temp-2*temp;
                }
                printf ("var %s binding is: %d\n", Lentry->name, binding);
                fprintf (filePointer, "MOV R%d, %d\n", resultReg, binding);
                fprintf (filePointer, "ADD R%d, BP\n", resultReg);
            } 

            else if (t->Gentry != NULL)
            fprintf (filePointer, "MOV R%d, %d\n", resultReg, t->Gentry->binding);
        }

        else if (t->left != NULL && t->left->nodeType != FIELD_NODE) {      //array[]
            resultReg = codeGen (t->left, filePointer);
            if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg, resultReg);
            fprintf (filePointer, "ADD R%d, %d\n", resultReg, t->Gentry->binding);
        }

        else if (t->left->nodeType == FIELD_NODE){  //field
            resultReg = codeGen (t->left, filePointer);
        }
        return resultReg;
    }

    else if (t->nodeType == WH){
        int label1 = getLabel(); push_label (label1);
        int label2 = getLabel(); push_label (label2);
        fprintf (filePointer, "L%d:\n", label1);
        int resultReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "JZ R%d, L%d\n", resultReg, label2);
        freeReg ();
        codeGen (t->right, filePointer);
        fprintf (filePointer, "JMP L%d\nL%d:\n", label1, label2);
        pop_label (); pop_label ();
        return -1;
    }

    else if (t->nodeType == IFNODE){
        printf ("if node\n");
        int label1 = getLabel();
        int resultReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "JZ R%d, L%d\n", resultReg, label1);
        freeReg ();
        codeGen (t->right, filePointer);
        fprintf (filePointer, "L%d:\n", label1);
        return -1;
    }

    else if (t->nodeType == IFELSE){
        printf ("ifelse node\n");
        int label1 = getLabel();
        int label2 = getLabel();
        int resultReg = codeGen (t->left, filePointer);
        fprintf (filePointer, "JZ R%d, L%d\n", resultReg, label1);
        freeReg ();
        codeGen (t->mid, filePointer);
        fprintf (filePointer, "JMP L%d\n", label2);
        fprintf (filePointer, "L%d:\n", label1);
        codeGen (t->right, filePointer);
        fprintf (filePointer, "L%d:\n", label2);
        freeReg();
        return -1;
    }

    else if (t->nodeType == BOOL){
        printf ("boolNode (%c)\n", t->op);
        int resultReg1 = codeGen (t->left, filePointer);
        if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg1, resultReg1);

        int resultReg2 = codeGen (t->right, filePointer);
        if (t->right->nodeType == IDENT || t->right->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg2, resultReg2);
        
        if (t->op == '<'){
            fprintf (filePointer, "LT R%d, R%d\n", resultReg1, resultReg2);
        }

        else if (t->op == 'l'){
            fprintf (filePointer, "LE R%d, R%d\n", resultReg1, resultReg2);
        }

        else if (t->op == '>'){
            fprintf (filePointer, "GT R%d, R%d\n", resultReg1, resultReg2);
        }

        else if (t->op == 'g'){
            fprintf (filePointer, "GE R%d, R%d\n", resultReg1, resultReg2);
        }

        else if (t->op == '='){
            fprintf (filePointer, "EQ R%d, R%d\n", resultReg1, resultReg2);
        }

        else if (t->op == 'n'){
            fprintf (filePointer, "NE R%d, R%d\n", resultReg1, resultReg2);
        }

        else if (t->op == '&'){
            if ((t->left->type == intType) | (t->right->type == intType)) {
                yyerror("type error !\n");
            }
            int tempReg = getReg ();
            fprintf (filePointer, "ADD R%d, R%d\n", resultReg1, resultReg2);
            fprintf (filePointer, "MOV R%d, 2\n", tempReg);
            fprintf (filePointer, "EQ R%d, R%d\n", resultReg1, tempReg);
            freeReg ();
        }

        else if (t->op == '|'){
            if ((t->left->type == intType) | (t->right->type == intType)) {
                yyerror("type error !\n");
            }
            fprintf (filePointer, "ADD R%d, R%d\n", resultReg1, resultReg2);
            int tempReg = getReg ();
            fprintf (filePointer, "MOV R%d, 0\n", tempReg);
            fprintf (filePointer, "NE R%d, R%d\n", resultReg1, tempReg);
            freeReg ();
        }

        freeReg ();
        return resultReg1;
    }

    else if (t->nodeType == FIELD_NODE){
        printf ("field node\n");
        int resultReg;
        if ((t->left != NULL) && (t->left->nodeType == FIELD_NODE)){
            resultReg = codeGen (t->left, filePointer);
            if (t->left->nodeType == IDENT || t->left->nodeType == FIELD_NODE)
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg, resultReg);
            if (t->left->type != NULL)
            fprintf (filePointer, "ADD R%d, %d\n", resultReg, FLookup(t->left->type, t->right->varName)->fieldIndex);
            else
            fprintf (filePointer, "ADD R%d, %d\n", resultReg, Class_FLookup (t->left->Ctype, t->right->varName)->Fieldindex);
            return resultReg;
        }
        else if ((t->left != NULL) && (t->left->nodeType == IDENT)){
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg, resultReg);
            int temp;
            if (t->left->type != NULL)
            temp = FLookup(t->left->type, t->right->varName)->fieldIndex;
            else
            temp = Class_FLookup (t->left->Ctype, t->right->varName)->Fieldindex;
            fprintf (filePointer, "ADD R%d, %d\n", resultReg, temp);
            return resultReg;
        }
        return -1;
    }

    else if (t->nodeType == CONT_STMT){
        if (!isEmpty())
        fprintf (filePointer, "JMP L%d\n", label_stack [top-1]);
        return -1;
    }

    else if (t->nodeType == BRK_STMT){
        if (!isEmpty())
        fprintf (filePointer, "JMP L%d\n", label_stack [top]);
        return -1;
    }
    return -1;
}

int evaluate(struct tnode * t) {
    printf ("evaluating\n");
    if (t->nodeType == CONNECTOR){
        evaluate (t->left);
        evaluate (t->right);
    }

    else if (t->nodeType == CONST){
        return (t->val);
    }

    else if (t->nodeType == IDENT){
        printf ("returning %d\n", t->val);
        return (t->val);
    }

    else if (t->nodeType == INPUT_STMT){
        // printf ("input %c:\n", t->left->op);
        // scanf ("%d", &variable_arr[varIndex(t->left->op)]);
    }

    else if (t->nodeType == OUTPUT_STMT){
        // printf ("%d\n", evaluate (t->left));
    }

    else if (t->nodeType == OP){
        switch (t->op){
            case '+' : return (evaluate (t->left) + evaluate (t->right)); break;
            case '-' : return (evaluate (t->left) - evaluate (t->right)); break;
            case '*' : return (evaluate (t->left) * evaluate (t->right)); break;
            case '/' : return (evaluate (t->left) / evaluate (t->right)); break;
            default : printf ("error\n");
        }
    }

    else if (t->nodeType == ASG_STMT){
        // variable_arr[varIndex(t->left->op)] = evaluate (t->right);
    }

    else if (t->nodeType == IFNODE){
        // if (evaluate (t->left)){
        //     evaluate (t->right);
        // }
        // return -1;
    }

    else if (t->nodeType == IFELSE){
        // if (evaluate (t->left)){
        //     evaluate (t->mid);
        // }
        // else {
        //     evaluate (t->right);
        // }
        // return -1;
    }

    else if (t->nodeType == BOOL){
        if (t->op == '<'){
            if (evaluate (t->left) < evaluate (t->right)) {
                return 1;
            }
            else return 0;
        }

        else if (t->op == 'l'){
            if (evaluate (t->left) <= evaluate (t->right)) return 1;
            else return 0;
        }

        else if (t->op == '>'){
            if (evaluate (t->left) > evaluate (t->right)) return 1;
            else return 0;
        }
        
        else if (t->op == 'g'){
            if (evaluate (t->left) >= evaluate (t->right)) return 1;
            else return 0;
        }

        else if (t->op == '='){
            if (evaluate (t->left) == evaluate (t->right)) return 1;
            else return 0;
        }

        else if (t->op == 'n'){
            if (evaluate (t->left) != evaluate (t->right)) return 1;
            else return 0;
        }
    }

    return -1;
}
