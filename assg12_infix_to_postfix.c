#include <stdio.h>
#include <ctype.h>
#include <string.h>
char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int precedence(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
void infixToPostfix(char *exp) {
    char x;
    printf("\nPostfix Expression: ");
    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];
        if (isalnum(c))
            printf("%c", c);
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            while (precedence(stack[top]) >= precedence(c))
                printf("%c", pop());
            push(c);
        }
    }
    while (top != -1)
        printf("%c", pop());
    printf("\n");
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%[^\n]", exp);
    infixToPostfix(exp);
    return 0;
}