#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char text[1000] = "", line[200];

    printf("Enter text (blank line to stop):\n");
    while (1) {
        gets(line);
        if (strlen(line) == 0) break;
        strcat(text, line);
        strcat(text, "\n");
    }

    // Remove leading spaces/tabs/newlines
    int i = 0;
    while (text[i] == ' ' || text[i] == '\t' || text[i] == '\n') i++;

    int len = strlen(text);
    while (len > 0 && (text[len - 1] == ' ' || text[len - 1] == '\t' || text[len - 1] == '\n'))
        text[--len] = '\0';

    if (text[i] == '/' && text[i + 1] == '/')
        printf("It is a SINGLE-LINE COMMENT.\n");
    else if (text[i] == '/' && text[i + 1] == '*' && len >= 4 &&
             text[len - 2] == '*' && text[len - 1] == '/')
        printf("It is a MULTI-LINE COMMENT.\n");
    else
        printf("It is NOT a comment.\n");

    return 0;
}
