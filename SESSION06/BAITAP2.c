//
// Created by DELL on 6/27/2025.
//
#include <stdio.h>
int fibonacci(int n, int pre, int next) {
    // 1. điều kiện dừng
    if (n<1) {
        return 0;
    }
    printf("%d -", pre);
    // 2. gọi hàm
    return fibonacci(n-1,next,pre+next);
}
int main() {
    int n;
    printf("nhap n so dau tien trong day fibonacci: ");
    scanf("%d", &n);
    fibonacci(n, 0, 1);
}

