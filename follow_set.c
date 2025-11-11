#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char prod[MAX][MAX];  // productions
int n;                // number of productions
char followRes[50];   // store FOLLOW result temporarily

// function prototypes
void follow(char c);
void first(char c);

void addToResult(char ch) {
    if (strchr(followRes, ch) == NULL)
        strncat(followRes, &ch, 1);
}

void first(char c) {
    if (!isupper(c)) { // terminal
        addToResult(c);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (prod[i][0] == c) {
            if (prod[i][3] == '\0')
                continue;
            if (!isupper(prod[i][3])) {
                addToResult(prod[i][3]);
            } else {
                first(prod[i][3]);
            }
        }
    }
}

void follow(char c) {
    // if start symbol
    if (prod[0][0] == c)
        addToResult('$');

    for (int i = 0; i < n; i++) {
        for (int j = 3; prod[i][j] != '\0'; j++) {
            if (prod[i][j] == c) {
                if (prod[i][j + 1] != '\0')
                    first(prod[i][j + 1]);
                else if (c != prod[i][0])
                    follow(prod[i][0]);
            }
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (like E->E+T):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", prod[i]);

    printf("\nFOLLOW Sets:\n");
    for (int i = 0; i < n; i++) {
        char nonterm = prod[i][0];
        strcpy(followRes, "");
        follow(nonterm);
        printf("FOLLOW(%c) = { ", nonterm);
        for (int j = 0; j < strlen(followRes); j++) {
            printf("%c ", followRes[j]);
        }
        printf("}\n");
    }

    return 0;
}
 
/*
input example
#of prods = 3
E->E+T
E->T
T->T*F
*/