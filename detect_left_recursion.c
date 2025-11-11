#include <stdio.h>
#include <string.h>

int main() {
    char prod[200];
    printf("Enter production (like A->Aa|b): ");
    scanf("%199s", prod);

    // find LHS nonterminal (before "->")
    char lhs = prod[0];

    // find start of RHS (after "->")
    char *rhs = strstr(prod, "->");
    if (!rhs) {
        printf("Invalid production format.\n");
        return 0;
    }
    rhs += 2; // move past "->"

    // split alternatives by '|', check each alternative's first symbol
    int leftRec = 0;
    char *alt = strtok(rhs, "|");
    while (alt != NULL) {
        // skip leading spaces (if any)
        int i = 0;
        while (alt[i] == ' ' || alt[i] == '\t') i++;

        if (alt[i] == lhs) { // immediate left recursion detected
            leftRec = 1;
            break;
        }
        alt = strtok(NULL, "|");
    }

    if (leftRec)
        printf("Immediate left recursion detected for %c.\n", lhs);
    else
        printf("No immediate left recursion detected for %c.\n", lhs);

    return 0;
}

/*
Input: A->Aa|b
Output: Immediate left recursion detected for A.

Input: E->E+T|T
Output: Immediate left recursion detected for E.

Input: S->aS|b
Output: No immediate left recursion detected for S.
*/