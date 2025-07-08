//
// Created by DELL on 7/8/2025.
//
// CÀI ĐẶT STACK BẰNG MẢNG
// TẠO MẢNG DATA ĐỂ CHỨA CÁC PHẦN TỬ TRONG STACK
// TẠO BIẾN TOP ĐỂ LƯU PHẦN TỬ TRÊN CÙNG CỦA NGĂN XẾP

#include <stdio.h>
#define MAX 100
typedef struct {
    int data[MAX];
    int top;
}Stack;
// HÀM KHỞI TẠO STACK
void initStack(Stack* s) {
    // ban đầu ngăn xếp rỗng, không có phần tử thì gán giá trị top=-1
    s->top = -1;
}
// HÀM KIỂM TRA STACK ĐÃ ĐẦY HAY CHƯA
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
// HÀM THÊM PHẦN TỬ
void push(Stack* s, int x) {
    // kiểm tra xem stack đã đầy hay chưa
    if (isFull(s)) {
        printf("Stack is full\n");
    }else {
        // thêm được phần tử và tăng top lên
        s->data[++(s->top)] = x;
    }
}
// HIỂN THỊ PHẦN TỬ
void printStack(Stack* s) {
    // HIỂN THỊ DANH SÁCH CÁC PHẦN TỬ BẮT ĐẦU TỪ PHẦN TỬ ĐỈNH
    for (int i = s->top; i >=0; i--) {
        printf("%d\n", s->data[i]);
    }
}
// HÀM KIỂM TRA NGĂN XẾP CÓ PHẦN TỬ HAY KHÔNG
int isEmpty(Stack* s) {
    // nếu =0 thì ngăn xếp có phần tử
    // nếu =1 thì ngăn xếp không có phần tử
    return s->top == -1;// kết quả về của hàm 0||1
}
// TOP(): XEM PHẦN TỬ Ở TRÊN ĐỈNH
int top(Stack* s) {
    // kiểm tra ngăn xếp có chua phần tử hay không
    if (isEmpty(s)) {
        // mảng không có phần tử nào
        return -1;
    }
    return s->data[s->top];
}
// HÀM ĐI XÓA PHẦN TỬ TRONG STACK
int pop(Stack* s) {
    // khi xóa phần tử trong stack kiểm tra xem ngăn xếp có phần tử hay không
    if (isEmpty(s)) {
        // ngăn xếp không có phần tử
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}
// HÀM HIỂN THỊ TRONG NGĂN XẾP CÓ BAO NHIÊU PHẦN TỬ
int size(Stack* s) {
    return s->top + 1;
}
int main() {
    Stack s;
    initStack(&s);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    push(&s, 5);
    push(&s, 7);
    // printStack(&s); // 1 2 3
    // printf("phan tu dinh %d",top(&s));
    // pop(&s);
    // pop(&s);
    // pop(&s);
    printf("so luong phan tu trong ngan xep %d",size(&s));
    // printStack(&s);
}
