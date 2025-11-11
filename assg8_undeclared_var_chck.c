// Assignment8.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char declared[100][20];
int count = 0;

int isDeclared(char *var) {
    for (int i = 0; i < count; i++)
        if (strcmp(declared[i], var) == 0)
            return 1;
    return 0;
}

int isKeyword(const char *t) {
    const char *kw[] = {"if","for","while","return","break","continue","else","switch","case"};
    for (int i = 0; i < 9; i++)
        if (strcmp(t, kw[i]) == 0) return 1;
    return 0;
}

int main() {
    char line[100], prev[20] = "";
    printf("Enter program lines (blank line to stop):\n");

    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "\n") == 0) break;

        char *token = strtok(line, " ,;(){}+-=*/\n\t");
        while (token) {
            if (strcmp(prev, "int") == 0 || strcmp(prev, "float") == 0 || strcmp(prev, "char") == 0) {
                strcpy(declared[count++], token);
                printf("Declared variable: %s\n", token);
            } else if (isalpha(token[0]) && !isKeyword(token)) {
                if (!isDeclared(token))
                    printf("Use of undeclared variable: %s\n", token);
            }
            strcpy(prev, token);
            token = strtok(NULL, " ,;(){}+-=*/\n\t");
        }
    }
    return 0;
}
