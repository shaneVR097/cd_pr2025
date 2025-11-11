#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char val;
    struct Node *left, *right;
} Node;

Node* newNode(char v) {
    Node* n = malloc(sizeof(Node));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

char stackOp[50];
Node* stackNd[50];
int topO = -1, topN = -1;

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '=') return 0;
    return -1;
}

void pushOp(char c){ stackOp[++topO] = c; }
char popOp(){ return stackOp[topO--]; }
char peekOp(){ return (topO==-1)?'\0':stackOp[topO]; }

void pushNd(Node* n){ stackNd[++topN] = n; }
Node* popNd(){ return stackNd[topN--]; }

void makeTree(char op){
    Node* r = popNd();
    Node* l = popNd();
    Node* n = newNode(op);
    n->left = l; n->right = r;
    pushNd(n);
}

Node* buildTree(char *exp){
    for(int i=0;i<strlen(exp);i++){
        char c=exp[i];
        if(isspace(c)) continue;
        if(isalnum(c)) pushNd(newNode(c));
        else if(c=='(') pushOp(c);
        else if(c==')'){
            while(peekOp()!='(') makeTree(popOp());
            popOp();
        } else {
            while(topO!=-1 && prec(peekOp())>=prec(c)) makeTree(popOp());
            pushOp(c);
        }
    }
    while(topO!=-1) makeTree(popOp());
    return popNd();
}

void printTree(Node* root,int space){
    if(!root) return;
    space+=5;
    printTree(root->right,space);
    printf("\n");
    for(int i=5;i<space;i++) printf(" ");
    printf("%c\n",root->val);
    printTree(root->left,space);
}

int main(){
    char expr[100];
    printf("Enter expression: ");
    scanf("%[^\n]",expr);

    Node* root = buildTree(expr);
    printf("\nParse Tree:\n");
    printTree(root,0);
    return 0;
}