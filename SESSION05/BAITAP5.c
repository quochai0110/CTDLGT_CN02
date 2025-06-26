//
// Created by DELL on 6/26/2025.
//
#include <stdio.h>
#include <string.h>
int kiemTraDoiXung(char arr[],int left, int right) {
    if (left >=right) {
        return 1;
    }
    if (arr[left] != arr[right]) {
        return 0;
    }
    return kiemTraDoiXung(arr,left+1,right-1);
}
int main() {
    char str[100];
    printf("nhap chuoi bat ky: ");// abcc
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;
    int len = strlen(str);
    int result = kiemTraDoiXung(str,0,len-1);
    if (result == 0) {
        printf("chuoi khong doi xung");
    }else {
        printf("la chuoi doi xung");
    }
}
