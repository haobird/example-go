/*
* 三缺一游戏
*/

#include <stdio.h>
int main()
{
    // char *cards = "JQK"; // 错误定义，此指针指向的只读存储器中
    char cards[] = "JQK"; // 正确定义，此指针指向的可读写存储器中
    char a_card = cards[2];
    cards[2] = cards[1];
    cards[1] = cards[0];
    cards[0] = cards[2];
    cards[2] = cards[1];
    cards[1] = a_card;
    puts(&a_card);
    printf("%c\n", a_card);
    puts(cards);
    printf("%p\n", cards);
    return 0;
}