//
// Created by DELL on 7/2/2025.
//
#include <stdio.h>
#include <stdlib.h>

// TẠO CẤU TRÚC NODE
// 1 NODE GỒM 2 THÀNH PHẦN ,DATA VÀ CON TRỎ TRỎ ĐẾN NODE TIẾP THEO
typedef struct Node {
 int data;
 struct Node* next;
}Node;
// tạo hàm thêm phần tử vào đầu danh sách
Node* insertElementAtHead(Node* head, int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}
// cập nhật phần tử theo giá trị
void updateByValue(Node* head, int oldValue, int newValue) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue;
            printf("cap nhat gia tri thanh cong \n");
            return;
        }
        current = current->next;
    }
}
// cập nhật phần tử theo vị trí
void updateByIndex(Node* head, int position, int newValue) {
    Node* current = head;
    int index=0;
    while (current != NULL) {
        if (index == position) {
            current->data = newValue;
            return;
        }
        current = current->next;
        index++;
    }

}
// HÀM XÓA PHẦN TỬ THEO GIÁ TRỊ
Node* deleteByValue(Node* head, int value) {
    Node* current = head;
    Node* pre = NULL;
    while (current != NULL) {
        if (current->data == value) {
            pre -> next = current->next;
            return  head;
        }
        pre = current;
        current = current->next;
    }
}

// tạo hàm hiển thị danh sách phần tử trong danh sách liên kết
void printList(Node* head) {
    while (head != NULL) {
        printf("%d \n ", head->data);
        head = head->next;
    }
}
int main() {
 // CRUD với danh sách liên kết đơn C: CREATE, R: READ, U: UPDATE, D: DELETE
 // Khởi tạo sanh sách liên kết đơn
 Node* head = NULL;
 // thêm phần tử vào trong danh sách
 head=insertElementAtHead(head,20);
 head=insertElementAtHead(head,40);
 head=insertElementAtHead(head,60);
    // gọi hàm hiển thị danh sách
    printf("danh sach ban dau \n");
    printList(head);
    // cap nhật theo giá trị
    printf("danh sach sau khi cap nhat gia tri");
    updateByValue(head,40,30);
    updateByIndex(head,1,50);
    deleteByValue(head,50);
    printList(head);
}

