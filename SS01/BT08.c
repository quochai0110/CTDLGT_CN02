//
// Created by DELL on 6/16/2025.
//

#include <stdio.h>
void main() {
    // KHAI BAO MANG BAT KI
    int arr[]= {1,2,3,4,5,3,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int maxCount=0; // KHAI BAO SO LAN PHAN TU XUAT HIEN LON NHAT
    int maxItem; // KHAI BAO PHAN TU LON NHAT
    for(int i=0;i<size;i++) {
        int count=0;
        for(int j=0;j<size;j++) {
            if(arr[i]==arr[j]) {
                count++;
            }
        }
        // ket thuc for di kiem tra count va maxcount
        if(count>maxCount) {
            maxCount=count;
            maxItem=arr[i];
        }
    }
    printf("phan tu xuat hien nhieu nhat : %d\n",maxItem);


}