//
// Created by DELL on 7/3/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef  struct Node {
    int data;
    struct Node* next;
}Node;
// hàm tạo node mới và thêm vào danh sách
Node* insertAtTail(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
//hàm đổi vị trí 2 phần tử liền kề đầu tiên
Node* swap(Node* head) {
    Node* newHead= head->next;
    Node* pre=NULL;
    Node* current=head;
    while (current!=NULL && current->next!=NULL) {
        Node* nextPair = current->next->next;
        Node* second = current->next;
        // đổi chỗ 2 node
        second->next=current;
        current->next=nextPair;
        if (pre!=NULL) {
            pre->next=second;
        }
        // cập nhật lại con trỏ
        pre=current;
        current=nextPair;
    }
    return newHead;
}
// hàm hiển thị
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main() {
    Node* head = NULL;
    head = insertAtTail(head, 1);
    head = insertAtTail(head, 2);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 4);
    head = insertAtTail(head, 5);
    printf("danh sach lien ket truoc khi dao \n");
    printList(head);
    head=swap(head);
    printf("\n");
    printf("danh sach lien ket truoc khi dao \n");
    printList(head);
}
