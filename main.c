#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *count(char *s) {
    int *x = calloc(26, sizeof(int));
    for(int i = 0; i < strlen(s); i++) {
        if(isblank(s[i])) continue;
        if(isalpha(s[i]))
            x[toupper(s[i])-'A']++;
    }
    return x;
}

int check(char *a, char *b) {
    int *x_a = count(a), *x_b = count(b);
    for(int i = 0; i < 26; i++) {
        if(x_a[i] != x_b[i]) {
            free(x_a);
            free(x_b);
            return 0;
        }
    }
    free(x_a);
    free(x_b);
    return 1;
}

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("2 args expected\n");
        exit(1);
    }
    if(check(argv[1], argv[2])) 
        printf("\"%s\" IS anagram of \"%s\"\n", argv[2], argv[1]);
    else
        printf("\"%s\" is NOT anagram of \"%s\"\n", argv[2], argv[1]);
    return 0;
}
