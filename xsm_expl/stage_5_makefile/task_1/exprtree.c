#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "exprtree.h"
#include "symbolTable.h"

struct tnode * makeLeafNode (int nodeType, char *val, int type){
    struct tnode * temp;
    temp = (struct tnode*) malloc (sizeof(struct tnode));
    temp->nodeType = nodeType;
    if (type == intType) temp->val = atoi(val);
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
    temp->varName = (char*)malloc(sizeof(varName));
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
    if ((nodeType == ASG_STMT && (left->type != right->type)) | (nodeType == ASG_STMT && (left->nodeType != IDENT))){
        yyerror("\ntype error !\n");
    }
    else if ((((nodeType == IFNODE) | (nodeType == IFELSE)) && (left->type != boolType))){
        yyerror("\ntype error !\n");
    }
    else if (nodeType == INPUT_STMT && left->nodeType != IDENT) {
        yyerror("\ntype error !\n");
    }

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
    fprintf (filePointer, "0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\nMOV SP, 4197\nPUSH R0 //retVal for main\nCALL MAIN\n");
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
        int resultReg;
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
        resultReg = codeGen (t->right, filePointer);    //return expression
        fprintf (filePointer, "MOV R%d, BP\n", tempReg);
        fprintf (filePointer, "SUB R%d, 2\n", tempReg);
        fprintf (filePointer, "MOV [R%d], R%d //store return val\n", tempReg, resultReg);
        temp = Lhead;
        while (temp != NULL){   //POP out local variables
            if (temp->binding>0)
            fprintf (filePointer, "POP R%d //pop loc var\n", tempReg); 
            temp = temp->next;
        }
        fprintf (filePointer, "MOV BP, [BP]\nPOP R0 //reset BP\n"); //reset BP
        fprintf (filePointer, "RET\n");
        freeReg ();
        return resultReg;
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

    else if (t->nodeType == RET_STMT){
        printf ("ret node\n");
        int resultReg = codeGen (t->left, filePointer);
        return resultReg;
    }

    else if (t->nodeType == OP){
        printf ("op node (%c)\n", t->op);
        if (t->op == '+'){
            int resultReg;
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "ADD R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            freeReg(filePointer);
            return resultReg;
        }

        else if (t->op == '-'){
            int resultReg;
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "SUB R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            freeReg(filePointer);
            return resultReg;
        }

        else if (t->op == '*'){
            int resultReg;
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "MUL R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            freeReg(filePointer);
            return resultReg;
        }

        else if (t->op == '/'){
            int resultReg;
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "DIV R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
            freeReg(filePointer);
            return resultReg;
        }

        else if (t->op == '%'){
            int resultReg1, resultReg2;
            int currReg = getReg ();
            resultReg1 = codeGen (t->left, filePointer);
            resultReg2 = codeGen (t->right, filePointer);
            fprintf (filePointer, "MOV R%d, R%d\n", currReg, resultReg1);
            fprintf (filePointer, "DIV R%d, R%d\n", resultReg1, resultReg2);
            fprintf (filePointer, "MUL R%d, R%d\n", resultReg2, resultReg1);
            fprintf (filePointer, "SUB R%d, R%d\n", currReg, resultReg2);
            freeReg(filePointer);
            freeReg(filePointer);
            return currReg;
        }
    }

    else if (t->nodeType == INPUT_STMT){
        printf ("read node\n");
        int currReg = getReg(filePointer);
        fprintf (filePointer, "MOV R%d, \"Read\"\nPUSH R%d\n", currReg, currReg);
        fprintf (filePointer, "MOV R%d, \"-1\"\nPUSH R%d\n", currReg, currReg);
        if (t->left->left == NULL) {//no expr (not array)
            struct Lsymbol * Lentry = LSymbolLookup(t->left->varName);
            if (Lentry != NULL){
                int binding = Lentry->binding;
                if (binding < 0){ //parameter
                    int temp = ((abs(currNBinding)-abs(binding))+2);
                    binding = temp-2*temp;
                }
                fprintf (filePointer, "MOV R%d, %d\n", currReg, binding);
                fprintf (filePointer, "ADD R%d, BP\n", currReg);
                fprintf (filePointer, "PUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", currReg);
            }

            else if (t->left->Gentry != NULL)
            fprintf (filePointer, "MOV R%d, %d\nPUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", currReg, t->left->Gentry->binding, currReg);
        }
            
        else {
            int resultReg = codeGen (t->left->left, filePointer);
            fprintf (filePointer, "ADD R%d, %d\n", resultReg, t->left->Gentry->binding);
            fprintf (filePointer, "PUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", resultReg);
            freeReg(filePointer);
        }
        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg(filePointer);
        return 0;
    }
    else if (t->nodeType == OUTPUT_STMT){
        printf ("write node\n");
        int resultReg;
        int currReg = getReg(filePointer);
        fprintf (filePointer, "MOV R%d, \"Write\"\nPUSH R%d\n", currReg, currReg);
        fprintf (filePointer, "MOV R%d, \"-2\"\nPUSH R%d\n", currReg, currReg);
        if (t->left->left == NULL) {//no expr (not array)
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "PUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", resultReg);
            freeReg ();
        }
        else {
            resultReg = codeGen (t->left->left, filePointer);
            fprintf (filePointer, "ADD R%d, %d\n", resultReg, t->left->Gentry->binding);
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg, resultReg);
            fprintf (filePointer, "PUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\n", resultReg);
            freeReg ();
        }
        fprintf (filePointer, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
        freeReg(filePointer);
        return 0;
    }

    else if (t->nodeType == ASG_STMT){
        printf ("assg node\n");
        int resultRegRight = codeGen (t->right, filePointer), resultReg;
        int currReg = getReg ();
        if (t->left->left == NULL) {  //no expr (not array)
            struct Lsymbol * Lentry = LSymbolLookup(t->left->varName);
            if (Lentry != NULL){
                int tempReg = getReg ();
                int binding = Lentry->binding;
                if (binding < 0){ //parameter
                    int temp = ((abs(currNBinding)-abs(binding))+2);
                    binding = temp-2*temp;
                }
                fprintf (filePointer, "MOV R%d, %d\n", tempReg, binding);
                fprintf (filePointer, "ADD R%d, BP\n", tempReg);
                fprintf (filePointer, "MOV [R%d], R%d\n", tempReg, resultRegRight);
                freeReg ();
            }

            else if (t->left->Gentry != NULL){
                fprintf (filePointer, "MOV [%d], R%d\n", t->left->Gentry->binding, resultRegRight);
            }
        }
        else if (t->left->left != NULL){  //array[]
            fprintf (filePointer, "MOV R%d, %d\n", currReg, t->left->Gentry->binding);
            resultReg = codeGen(t->left->left, filePointer);
            fprintf (filePointer, "ADD R%d, R%d\n", currReg, resultReg);
            fprintf (filePointer, "MOV [R%d], R%d\n", currReg, resultRegRight);
        }
        freeReg ();
        freeReg ();
        freeReg ();
    }

    else if (t->nodeType == CONST){
        printf ("const node (%d)\n", t->val);
        int resultReg = getReg(filePointer);
        if (t->type == intType)
        fprintf (filePointer, "MOV R%d, %d\n", resultReg, t->val);
        else if (t->type == strType)
        fprintf (filePointer, "MOV R%d, %s\n", resultReg, t->strVal);
        return resultReg;
    }

    else if (t->nodeType == IDENT){
        printf ("ident node ()\n");
        int resultReg;
        if (t->left == NULL){
            resultReg = getReg(filePointer);
            struct Lsymbol * Lentry = LSymbolLookup(t->varName);
            if (Lentry != NULL){
                int tempReg = getReg ();
                int binding = Lentry->binding;
                if (binding < 0){ //parameter
                    int temp = ((abs(currNBinding)-abs(binding))+2);
                    binding = temp-2*temp;
                }
                printf ("var %s binding is: %d\n", Lentry->name, binding);
                fprintf (filePointer, "MOV R%d, %d\n", tempReg, binding);
                fprintf (filePointer, "ADD R%d, BP\n", tempReg);
                fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg, tempReg);
                freeReg(filePointer);
            } 

            else if (t->Gentry != NULL)
            fprintf (filePointer, "MOV R%d, [%d]\n", resultReg, t->Gentry->binding);
        }

        else if (t->left != NULL) {      //array[]
            resultReg = codeGen (t->left, filePointer);
            fprintf (filePointer, "ADD R%d, %d\n", resultReg, t->Gentry->binding);
            fprintf (filePointer, "MOV R%d, [R%d]\n", resultReg, resultReg);
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
        freeReg(filePointer);
        return -1;
    }

    else if (t->nodeType == BOOL){
        printf ("boolNode (%c)\n", t->op);
        int resultReg = codeGen (t->left, filePointer);
        if (t->op == '<'){
            fprintf (filePointer, "LT R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == 'l'){
            fprintf (filePointer, "LE R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == '>'){
            fprintf (filePointer, "GT R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == 'g'){
            fprintf (filePointer, "GE R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == '='){
            fprintf (filePointer, "EQ R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == 'n'){
            fprintf (filePointer, "NE R%d, R%d\n", resultReg, codeGen(t->right, filePointer));
        }

        else if (t->op == '&'){
            if ((t->left->type == intType) | (t->right->type == intType)) {
                yyerror("type error !\n");
            }
            int tempReg = getReg ();
            fprintf (filePointer, "ADD R%d, R%d\n", resultReg, codeGen (t->right, filePointer));
            fprintf (filePointer, "MOV R%d, 2\n", tempReg);
            fprintf (filePointer, "EQ R%d, R%d\n", resultReg, tempReg);
            freeReg ();
        }

        else if (t->op == '|'){
            if ((t->left->type == intType) | (t->right->type == intType)) {
                yyerror("type error !\n");
            }
            fprintf (filePointer, "ADD R%d, R%d\n", resultReg, codeGen (t->right, filePointer));
            int tempReg = getReg ();
            fprintf (filePointer, "MOV R%d, 0\n", tempReg);
            fprintf (filePointer, "NE R%d, R%d\n", resultReg, tempReg);
            freeReg ();
        }

        freeReg ();
        return resultReg;
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
