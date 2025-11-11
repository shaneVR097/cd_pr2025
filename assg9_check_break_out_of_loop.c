#include <stdio.h>
#include <string.h>

int main() {
    char line[100];
    int loopFlag = 0;
    printf("Enter program lines (blank line to stop):\n");
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, "\n") == 0) break;

        if (strstr(line, "for") || strstr(line, "while") || strstr(line, "do"))
            loopFlag++;
        if (strstr(line, "break")) {
            if (loopFlag == 0)
                printf("Break used outside loop.\n");
            else
                printf("Break used inside loop.\n");
        }
        if (strstr(line, "}")) {
            if (loopFlag > 0) loopFlag--;
        }
    }
    return 0;
}
