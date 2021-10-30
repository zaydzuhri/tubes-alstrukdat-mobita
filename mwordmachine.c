#include "wordmachine.h"
#include <stdio.h>
int main() {
    FILE *file;
    file = fopen("config.txt", "r");
    startWord();
    printf(currentWord.contents);
    startWord();
    printf(currentWord.contents);
    startWord();
    printf(currentWord.contents);
    // printf(endWord ? "yep" : "no");
    return 0;
}