//
// Created by DELL on 6/26/2025.
//
#include <stdio.h>
int fibonacci(int arr[], int n, int index, int next) {
    if (index > n) {
        return 0;
    }
    if (index==0) {
        arr[index] = 0;
    }else if (index==1) {
        arr[index] = 1;
    }else {
        arr[index] = next;
        next += arr[index-1];

    }

    return  fibonacci(arr, n, index+1, next);

}
int main() {

    int n;
    printf("nhap so luong so fibonaci: ");
    scanf("%d", &n);
    int arr[n];
    fibonacci(arr,n,0,1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}
