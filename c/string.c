/*
* 字符串操作
*/

#include <stdio.h>
#include <string.h>

int main() {
    char msg[] = "Hello";
    char * pos = strstr(msg, "llo");
    printf("%p\n", pos);
    if (pos) {
        printf("%s\n", msg);
    }
    return 0;
}