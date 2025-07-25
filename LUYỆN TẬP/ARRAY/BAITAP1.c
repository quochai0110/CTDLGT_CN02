#include <stdio.h>
//  CHO 2 MẢNG ĐÃ ĐƯỢC SẮP XẾP TĂNG DẦN
// YÊU CẦU TRỘN 2 MẢNG NÀY THÀNH 1 MẢNG SẮP XẾP TĂNG DẦN
// INPUT : MANG1 [1,3,5,7], MANG2 [2,4,6,8,10]
// OUTPUT: RESULT[1,2,3,4,5,6,7,8,9,10]
void sort(int arrA[],int n,int arrB[], int m, int arrC[10]) {
    int i=0,j=0,k=0;
    while (i<n&&j<m) {
        if (arrA[i]<=arrB[j]) {
            arrC[k]=arrA[i];
            i++;
            k++;
        }else {
            arrC[k]=arrB[j];
            j++;
            k++;
        }
    }
    while (i<n) {
        arrC[k++]=arrA[i++];
    }
    while (j<m) {
        arrC[k++]=arrB[j++];
    }
    for (int l =0; l<k; l++) {
        printf("%d ",arrC[l]);
    }
    printf("\n");
}
int main() {
    int arrA[]={1,3,5,7,9};
    int arrB[]={2,4,6,8,10};
    int arrC[10];
    sort(arrA,5,arrB,5,arrC);
}

