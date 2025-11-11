#include <stdio.h>
#include <string.h>

void findFirst(char *prod) {
    printf("FIRST(%c) = { ", prod[0]);
    for (int i = 3; i < strlen(prod); i++) {
        if (prod[i] >= 'a' && prod[i] <= 'z') {
            printf("%c ", prod[i]);
            break;
        } else if (prod[i] == '|') continue;
    }
    printf("}\n");
}

int main() {
    char prod[50];
    printf("Enter production (example: E->aA|b): ");
    scanf("%s", prod);
    findFirst(prod);
    return 0;
}

/*
Example Inputs & Outputs:
1?? E->aA|b  ?  FIRST(E) = { a }
2?? S->bB|a  ?  FIRST(S) = { b }
3?? A->e|dA  ?  FIRST(A) = { e }
*/
