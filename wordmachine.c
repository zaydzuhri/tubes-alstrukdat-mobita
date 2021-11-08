#include "wordmachine.h"
#include <stdio.h>

Word currentWord;
boolean endWord;

void ignoreBlank() {
    /* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang 
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* KAMUS */
    /* ALGORITMA */
    while (currentChar == BLANK) {
        adv();
    }
}

void ignoreNewLine() {
    while (currentChar == MARK) {
        adv();
    }
}

void startWord() {
    /* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    /* KAMUS */
    /* ALGORITMA */
    start();
    ignoreBlank();
    if (currentChar == MARK)
        endWord = true;
    else {
        endWord = false;
        copyWord();
    }
}

void startWordFile(FILE *file) {
    /* I.S. : currentChar sembarang 
   F.S. : endWord = true, dan currentChar = MARK; 
          atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    /* KAMUS */
    /* ALGORITMA */
    startFile(file);
    ignoreBlank();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        endWord = false;
        copyWord();
    }
}

void advWord() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
    /* KAMUS */
    /* ALGORITMA */
    ignoreBlank();
    if (currentChar == MARK)
        endWord = true;
    else {
        copyWord();
        ignoreBlank();
    }
}

void advWordFile() {
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi 
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi, 
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, endWord = true.		  
   Proses : Akuisisi kata menggunakan procedure copyWord */
    /* KAMUS */
    /* ALGORITMA */
    ignoreBlank();
    if (currentChar == MARK) {
        endWord = true;
        copyWord();
        ignoreBlank();
        ignoreNewLine();
    } else {
        copyWord();
        ignoreBlank();
        ignoreNewLine();
    }
}

void copyWord() {
    /* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi; 
          currentChar = BLANK atau currentChar = MARK; 
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    i = 0;

    for (int i = 0; i < currentWord.length; i++) {
        currentWord.contents[i] = '\0';
    }

    do {
        currentWord.contents[i] = currentChar;
        i++;
        adv();
    } while (currentChar != MARK && currentChar != BLANK && i < CAP);
    currentWord.length = i;
}

boolean isSameString(Word str1, char str2[]) {
    boolean isSame = true;
    for (int i = 0; i < str1.length && isSame; i++) {
        isSame = str1.contents[i] == str2[i];
    }
    return isSame;
}