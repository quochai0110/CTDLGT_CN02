//
// Created by DELL on 6/26/2025.
//
// 1. xác định điều kiện dừng
// 2. xử lý logic để tạo ra điểm dừng
#include <stdio.h>
// tinh tong tu 1 den n
int sum( int n) {
    // printf("ham tinh tong\n");
    if (n==1) {
        return 1;
    }
    return n+sum(n-1);

}
// tinh giai thua tu 1 den n : n*(n-1) * (n-2) ... * 1
int factorial(int n) {
    if (n==1) {
        return 1;
    }
    return n*factorial(n-1);
}
int main() {
    int result= sum(5);
    printf("%d \n",result);
    int result2= factorial(5);
    printf("%d",result2);
}