//
// Created by DELL on 7/1/2025.
//
#include <math.h>
#include <stdio.h>
// tạo hàm sắp xếp các phần tử theo khoảng cách
int sortByDistance(int arr[], int x, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int temp1= abs(arr[j]-x);
            int temp2= abs(arr[j+1]-x);
            if (temp1>temp2|| temp1==temp2 && arr[j]>arr[j+1]) {
                // thỏa mãn điều kiện đi đổi chỗ
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    // hiển thị kết quả
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int arr[]={10, 5, 3, 9, 2};
    int len = sizeof(arr)/sizeof(arr[0]);
    int x=7;
    sortByDistance(arr, x, len);
}
