/**
Filename: pcolor.h
Description: Print character with some color in terminal
Prepared by: Asisten IF2110
Created at: 17/10/2019
**/

/**
Details

print_xxx(c) will print c with xxx color. Import this header to use the declared functions.
We only provide 8 colors. Feel free to modify/add colors if you want to.
**/

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define BLACK "\x1B[30m"
#define WHITE "\x1B[37m"

void print_red(char c);
void print_green(char c);
void print_yellow(char c);
void print_blue(char c);
void print_magenta(char c);
void print_cyan(char c);
void print_black(char c);
void print_white(char c);
void print_normal();
