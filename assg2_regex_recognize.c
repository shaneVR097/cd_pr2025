#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool match_a(const char *s){
    return (strcmp(s, "a")==0); //return (strcmp(s, "a")==0);
}

bool match_a_star_b_plus(const char *s){
    int i=0, n=strlen(s);     // a*b+ : zero or more 'a' followed by one or more 'b', and nothing else
    while (i<n && s[i]=='a') i++;
    int bcount = 0;
    while (i<n && s[i]=='b') { bcount++; i++; }
    return (bcount>=1 && i==n);
}

bool match_abb(const char *s){
    return (strcmp(s, "abb")==0);
}

int main(){
    char s[256];
    printf("Enter string: ");
    scanf("%255s", s);
    printf("Matches 'a': %s\n", match_a(s) ? "YES" : "NO");
    printf("Matches 'a*b+': %s\n", match_a_star_b_plus(s) ? "YES" : "NO");
    printf("Matches 'abb': %s\n", match_abb(s) ? "YES" : "NO");
    return 0;
}
