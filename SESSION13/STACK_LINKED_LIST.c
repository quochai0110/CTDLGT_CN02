//
// Created by DELL on 7/8/2025.
//
#include <stdio.h>
#include <stdlib.h>
// KHỞI TẠO NGĂN XẾP VỚI DANH SÁCH LIÊN KẾT ĐƠN
// TỪNG PHẦN TỬ LÀ 1 NODE CHỨA DỮ LIỆU VÀ CON TRỎ NEXT
// CON TRỎ TOP TRỎ TỚI NODE TRÊN CÙNG

 typedef struct Node {
  int data;
  struct Node* next;
 }Node;
typedef struct {
 Node* top;
}Stack;
// HÀM KHỞI TẠO STACK
void initStack(Stack* s) {
 s->top = NULL;
}
// THÊM PHẦN TỬ VÀO STACK
void push(Stack* s, int value) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = value;
 newNode->next = s->top;
 s->top = newNode;
}
// TẠO HÀM HIỂN THỊ PHẦN TỬ TRONG NGĂN XẾP
void printfStack(Stack* s) {
 Node* temp = s->top;
 while (temp != NULL) {
  printf("%d ", temp->data);
  temp = temp->next;
 }
}
int main() {
 Stack s;
 initStack(&s);
 push(&s, 1);
 push(&s, 2);
 push(&s, 3);
 printfStack(&s);
}
