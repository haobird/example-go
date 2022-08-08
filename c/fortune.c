/*
* 字符串操作
*/

#include <stdio.h>

int fortune_cookie(char msg[])
{
    printf("Message reads: %s\n", msg);
    *msg = "Y";
    printf("Message reads: %s\n", msg);
    // printf("msg occupies %lu bytes\n", sizeof(msg));
    return 0;
}

int main() {
    char  quote[] = "Hello";
    fortune_cookie( quote);
    printf("Quote reads: %s\n", quote);
    // quote = "You will be rich and famous!";
    // printf("Quote reads: %s\n", quote);
}

