#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool is_valid_identifier(const char *s){
    
	if (!s || !s[0]) 
		return false;
    
	if (!(isalpha((unsigned char)s[0]) || s[0]=='_')) 
		return false;
    
	for (int i=1; s[i]; ++i)
        if (!(isalnum((unsigned char)s[i]) || s[i]=='_')) 
			return false;

    return true;
}

int main(){
    char s[256];
    printf("Enter identifier: ");
    scanf("%255s", s);
    printf("%s is %s\n", s, is_valid_identifier(s) ? "a valid identifier" : "NOT a valid identifier");
    return 0;
}