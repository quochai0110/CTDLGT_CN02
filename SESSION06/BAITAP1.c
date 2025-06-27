//
// Created by DELL on 6/27/2025.
#include <stdio.h>

int recursion(int number) {
    // 1. điều kiện dừng
    if (number==0) {
        return 0;
    }
     recursion(number/2);
     printf("%d", number%2);
    // 2. gọi lại hàm
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    recursion(number);

}