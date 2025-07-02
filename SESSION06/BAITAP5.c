//
// Created by DELL on 6/27/2025.
//
#include <stdio.h>
int findMax(int arr[], int size, int i) {
    // 1. điều kiện dừng
        if (i==size-1) {
            return arr[i];
        }
    int max = findMax(arr, size, i+1);
    // 2. ham gọi đệ quy
        return (arr[i]>max?arr[i]:max);

}
int main() {
    int n;
    printf("nhap so luong phan tu trong mangr: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu  thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max = findMax(arr, n, 0);
    printf("max trong mang: %d\n", max);
}