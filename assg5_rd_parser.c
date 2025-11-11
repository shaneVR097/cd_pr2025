// Assignment5.c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char s[100];
int pos = 0;

void skipSpaces() {
    while (isspace(s[pos])) pos++;
}

char peek() {
    skipSpaces();
    return s[pos];
}

char getChar() {
    skipSpaces();
    return s[pos++];
}

int E();
int T();
int F();

int Ep() {
    char c = peek();
    if (c == '+' || c == '-') {
        getChar();
        if (!T()) return 0;
        return Ep();
    }
    return 1;
}

int Tp() {
    char c = peek();
    if (c == '*' || c == '/') {
        getChar();
        if (!F()) return 0;
        return Tp();
    }
    return 1;
}

int E() {
    if (!T()) return 0;
    return Ep();
}

int T() {
    if (!F()) return 0;
    return Tp();
}

int F() {
    char c = peek();
    if (c == '(') {
        getChar();
        if (!E()) return 0;
        if (peek() == ')') { getChar(); return 1; }
        return 0;
    }
    if (isalnum(c)) {
        getChar();
        return 1;
    }
    return 0;
}

int main() {
    printf("Enter expression (single-letter ids/digits): ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    pos = 0;
    int ok = E() && (peek() == '\0');
    printf(ok ? "Input accepted by LL(1)/recursive-descent parser.\n" : "Input rejected.\n");
    return 0;
}
