#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isOperator(const char *tok) {
    const char *ops[] = {"+","-","*","/","%","++","--","==","!=","<",">","<=",">=","&&","||","!","=","+=","-=","*=","/=","%=","<<",">>" };
    int n = sizeof(ops)/sizeof(ops[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(tok, ops[i]) == 0)
            return true;
    }
    return false;
}

int main() {
    char line[256];
    printf("Enter operators or tokens separated by space:\n");
    fgets(line, sizeof(line), stdin);
    char *token = strtok(line, " \t\n"); // Tokenize by space
    while (token != NULL) {
        if (isOperator(token))
            printf("'%s' -> valid operator\n", token);
        else
            printf("'%s' -> not a recognized operator\n", token);
        token = strtok(NULL, " \t\n");
    }
    return 0;
}
