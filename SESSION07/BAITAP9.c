//
// Created by DELL on 7/1/2025.
//
#include <stdio.h>
int sort(int arr[], int n) {
 int count_even=0;
    int count_odd=0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count_even++;
        }else {
            count_odd++;
        }
    }
    int even[count_even];
    int odd[count_odd];
    int evenCount=0;
    int oddCount=0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount] = arr[i];
            evenCount++;
        }else {
            odd[oddCount] = arr[i];
            oddCount++;
        }
    }
    // tiến hành sắp xếp mảng số chẵn theo thứ tự tăng dần
    for (int i = 0; i < evenCount-1; i++) {
        for (int j = 0; j < evenCount-i-1; j++) {
            if (even[j] > even[j+1]) {
                int temp = even[j];
                even[j] = even[j+1];
                even[j+1] = temp;
            }
        }
    }
    // tiến hành sắp xếp mảng số lẻ theo thứ tự giảm dần
    for (int i = 0; i < oddCount-1; i++) {
        for (int j = 0; j < oddCount-i-1; j++) {
            if (odd[j] < odd[j+1]) {
                int temp = odd[j];
                odd[j] = odd[j+1];
                odd[j+1] = temp;
            }
        }
    }
    // gộp 2 mảng đã được sắp xếp
    int k=0;
    for (int i = 0; i < evenCount; i++) {
        arr[k] = even[i];
        k++;
    }
    for (int i = 0; i < oddCount; i++) {
        arr[k] = odd[i];
        k++;
    }
    // hiển thị kết quả
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int main() {
    int n;
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu %d : ",i+1);
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
}