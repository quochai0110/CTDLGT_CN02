//
// Created by DELL on 6/26/2025.
//
#include  <stdio.h>
// arr[3] ={2,4,6}
int sum(int arr[],int n) {
    if (n==0) return 0;
    return arr[n-1]+sum(arr,n-1);
    // 6+ 4+ 2
}
int main() {
    int n;
    printf(": nhap so luong phan tu ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf(": nhap phan tu ");
        scanf("%d", &arr[i]);
    }
    int result = sum(arr, n);
    printf(" so luong phan tu %d = %d", n, result);

}