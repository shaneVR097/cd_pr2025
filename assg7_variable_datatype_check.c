// Assignment7.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isInteger(const char *v) {
    for (int i = 0; v[i]; i++) if (!isdigit(v[i]) && !(i == 0 && v[i] == '-')) return 0;
    return 1;
}

int isFloat(const char *v) {
    int dot = 0;
    for (int i = 0; v[i]; i++) {
        if (v[i] == '.') { if (dot++) return 0; }
        else if (!isdigit(v[i]) && !(i == 0 && v[i] == '-')) return 0;
    }
    return dot;
}

int isCharLiteral(const char *v) {
    return strlen(v) == 3 && v[0] == '\'' && v[2] == '\'';
}

int main() {
    char line[100], type[20], var[20], val[30];
    printf("Enter declarations (blank line to stop):\n");
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "\n") == 0) break;

        if (sscanf(line, "%s %s = %s", type, var, val) == 3) {
            val[strcspn(val, ";\n")] = 0;
            if (strcmp(type, "int") == 0)
                printf("%s %s = %s ? %s\n", type, var, val, isInteger(val) ? "Compatible" : "Not Compatible");
            else if (strcmp(type, "float") == 0 || strcmp(type, "double") == 0)
                printf("%s %s = %s ? %s\n", type, var, val, (isFloat(val) || isInteger(val)) ? "Compatible" : "Not Compatible");
            else if (strcmp(type, "char") == 0)
                printf("%s %s = %s ? %s\n", type, var, val, isCharLiteral(val) ? "Compatible" : "Not Compatible");
        }
    }
    return 0;
}
