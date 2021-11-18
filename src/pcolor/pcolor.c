/**
Filename: pcolor.c (implementation of pcolor.h)
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

#include <stdio.h>
#include "pcolor.h"

void print_red(char c) {
    printf("%s%c", RED, c);
    printf("%s", WHITE);
}

void print_green(char c) {
    printf("%s%c", GREEN, c);
    printf("%s", WHITE);
}

void print_yellow(char c) {
    printf("%s%c", YELLOW, c);
    printf("%s", WHITE);
}

void print_blue(char c) {
    printf("%s%c", BLUE, c);
    printf("%s", WHITE);
}

void print_magenta(char c) {
    printf("%s%c", MAGENTA, c);
    printf("%s", WHITE);
}

void print_cyan(char c) {
    printf("%s%c", MAGENTA, c);
    printf("%s", WHITE);
}

void print_black(char c) {
    printf("%s%c", BLACK, c);
    printf("%s", WHITE);
}

void print_white(char c) {
    printf("%s%c", WHITE, c);
    printf("%s", WHITE);
}
void print_normal() {
    printf("%s", BLACK);
}