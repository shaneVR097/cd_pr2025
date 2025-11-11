#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
int tempCount = 1;

void push(char c) { stack[++top] = c; } // Stack operations
char pop() { return stack[top--]; }
char peek() { return (top == -1) ? '\0' : stack[top]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void generate3AC(char *expr) { // Generate three-address code using postfix conversion
    char postfix[MAX], stOp[MAX];
    int i, j = 0;
    top = -1;

    // Convert infix to postfix
    for (i = 0; i < strlen(expr); i++) {
        char c = expr[i];
        if (isspace(c)) continue;
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("\nPostfix: %s\n", postfix); // Generate three-address code from postfix
    printf("\nThree Address Code:\n");

    char tempVars[MAX][10];
    int tempTop = -1;

    for (i = 0; i < strlen(postfix); i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            char str[2] = {c, '\0'};
            strcpy(tempVars[++tempTop], str);
        } else {
            char op2[10], op1[10], res[10];
            strcpy(op2, tempVars[tempTop--]);
            strcpy(op1, tempVars[tempTop--]);
            sprintf(res, "t%d", tempCount++);
            printf("%s = %s %c %s\n", res, op1, c, op2);
            strcpy(tempVars[++tempTop], res);
        }
    }
    printf("Result stored in: %s\n", tempVars[tempTop]);
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%[^\n]", expr);
    generate3AC(expr);
    return 0;
}
