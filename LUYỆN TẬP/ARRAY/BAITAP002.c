// CHO 1 MẢNG BAT KI
// YÊU CAU HIỂN THỊ PHẦN TỬ LẺ TĂNG DẦN
// YÊU CẦU HIỂN THỊ PHẦN TỬ CHẴN TANG DẦN
// INPUT [4,1,11,6,8,7]
// OUTPUT: LẺ : 1, 7, 11
//         CHẴN 4,6,8
#include <stdio.h>

int main() {
    int n;
    printf("nhap vao so luong phan tu mang");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("nhap vao cac phan tu cua mang");
        scanf("%d", &arr[i]);
    }
    int arrEven[100], arrOdd[100];
    int even = 0, odd = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arrEven[even] = arr[i];
            even++;
        } else {
            arrOdd[odd] = arr[i];
            odd++;
        }
    }

    for (int i = 0; i < even; i++) {
        for (int j = 0; j < even - i - 1; j++) {
            if (arrEven[j] > arrEven[j+1]) {
                int temp = arrEven[j];
                arrEven[j] = arrEven[j+1];
                arrEven[j+1] = temp;
            }
        }
    }

    printf("mang chan:");
    for (int i = 0; i < even; i++) {
        printf("%d ", arrEven[i]);
    }
    return 0;
}