/*
* 打印指针
*/
#include <stdio.h>
int main() {
    int x = 5;
    int * p;
    p = &x;
    printf("%p\n", p);

    int new = * p;
    printf("%d\n", new);

    char msg[] = "Hello";
    printf("%p\n", msg);
}