/*
 * 计算牌数
 *
*/

# include <stdio.h>

int main() {
    int decks;
    puts("How many decks do you want to play with? ");
    scanf("%d", &decks);
    if (decks < 1){
        printf("You must have at least one deck.\n");
        return 1;
    }
    printf("There are %d cards in %d decks.\n", 52 * decks, decks);
    return 0;
}