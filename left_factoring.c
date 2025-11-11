#include <stdio.h>
#include <string.h>

int main() {
    char prod[20], part1[10], part2[10];
    int i, j = 0, k = 0, pos;

    printf("Enter production (example: E->aA|aB): ");
    scanf("%s", prod);

    pos = strchr(prod, '|') - prod;
    for (i = 3; i < pos; i++)
        part1[j++] = prod[i];
    part1[j] = '\0';

    for (i = pos + 1; i < strlen(prod); i++)
        part2[k++] = prod[i];
    part2[k] = '\0';

    j = 0;
    while (part1[j] && part2[j] && part1[j] == part2[j]) j++;

    if (j == 0)
        printf("No Left Factoring.\n");
    else {
        printf("Left Factored Grammar:\n");
        printf("%c->", prod[0]);
        for (i = 0; i < j; i++) printf("%c", part1[i]);
        printf("%c'\n", prod[0]);
        printf("%c'->%s|%s\n", prod[0], part1 + j, part2 + j);
    }

    return 0;
}

/*
Example Inputs & Outputs:
1 E->aA|aB  ?  Left Factored Grammar:
                 E->aE'
                 E'->A|B
2 S->ab|ac  ?  S->aS'
                 S'->b|c
3 A->xy|pq  ?  No Left Factoring.
*/
