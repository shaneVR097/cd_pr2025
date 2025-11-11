// Assignment6.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int reduceOnce() {
    if (top >= 2 && stack[top] == 'i' && isOperator(stack[top - 1]) && stack[top - 2] == 'i') {
        top -= 2; // remove i, op
        stack[top] = 'i'; // reduce to id
        return 1;
    }
    return 0;
}

int main() {
    char expr[100];
    printf("Enter arithmetic expression (single-letter ids/digits): ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;

    top = -1;
    push('$');
    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];
        if (isspace(c)) continue;

        if (isalnum(c)) push('i');
        else if (c == '(') push('(');
        else if (c == ')') {
            while (top >= 0 && peek() != '(') {
                if (!reduceOnce()) break;
            }
            if (peek() == '(') pop();
        } else if (isOperator(c)) {
            while (top > 0 && isOperator(peek()) && precedence(peek()) >= precedence(c)) {
                if (!reduceOnce()) break;
            }
            push(c);
        }
    }
    while (reduceOnce());

    if (top == 1 && stack[0] == '$' && stack[1] == 'i')
        printf("Input accepted by shift-reduce (bottom-up) parser.\n");
    else
        printf("Input rejected.\n");
    return 0;
}
