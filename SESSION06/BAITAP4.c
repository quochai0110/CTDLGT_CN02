//
// Created by DELL on 6/27/2025.
//

#include <stdio.h>
int tower(int n,char A,char B, char C) {
    // buoc 1: dich chuyen n-1 dia tu cot A sang cot trung gian B
    if(n==0) {
        return 0;
    }
    tower(n-1,A,C,B);
    printf("  di chuyen tu %c den %c \n",A,C);
    // buoc 2: dic chuyen n-1 dia tu cot trung gian B sang C
    tower(n-1,B,A,C);
}
int main() {
    int n;
    printf("nhap so luong dia");
    scanf("%d", &n);
    if (n==1) {
        printf("dia 1 di chuyen tu A sang C");
        return 0;
    }
    tower(n,'A','B','C');

}