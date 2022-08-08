/*
* 输出数据
*/
#include <stdio.h>

int myInt(){
    int age;
    printf("Enter your age: ");
    scanf("%i", &age);
    printf("%i\n", age);
    return 0;
}

int myStr() {
    char first_name[20];
    char last_name[20];
    printf("Enter first and last name: ");
    scanf("%19s,%19s", first_name, last_name);
    printf("First: %s Last:%s\n", first_name, last_name);
    return 0;
}

int outStr() {
    char food[5];
    printf("Enter favorite food: ");
    scanf("%s", food);
    printf("Favorite food: %s\n", food);
    return 0;
}


int main() {
    myStr();
    return 0;
}

