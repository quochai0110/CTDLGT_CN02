//
// Created by DELL on 7/4/2025.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// khởi tạo cấu node

typedef  struct Node {
    int data;
    struct Node* pre;
    struct Node* next;
}Node;
// thêm phần tử vào vị trí đầu
Node* insertAtHead(Node* head,int value) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->pre=NULL;
    newNode->next=head;
    if(head!=NULL) {
        head->pre=newNode;
    }
    return newNode; // node đầu bây giờ sẽ là newNode
}
// thêm phần tử vào cuối danh sách
Node* insertAtTail(Node* head,int value) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->pre=NULL;
    // nếu danh sách rỗng, nếu mới chính là node đầu tiên luôn
    if(head==NULL) {
        return newNode;
    }
    Node* temp=head;
    // lấy phần tử cuối cùng
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->pre=temp;
    return head;
}
// thêm vào vị trí bất kì
Node* insertAtPosition(Node* head,int value,int position) {
    // trước khi tạo node phải kiểm tra xem vị trí người dùng nhập có hợp le hay không
    if (position<0) {
        printf(" vi tri khong hop le\n");
        return head;
    }
    if (position==0) {
        // quay về bài toán thêm vào đầu
        return insertAtHead(head,value);
    }
    // đi khởi tạo node
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=value;
    Node* temp=head;
    // duyệt đến node đứng trước vị trí cần chèn
    int index=0;
    while(temp!=NULL && index<position-1) {
        temp=temp->next;
        index++;
    }
    newNode->next=temp->next;
    newNode->pre=temp;
    // nếu node sau temp tồn tại thì phải trỏ đến ngược lại node mới
    if (temp->next!=NULL) {
        temp->next->pre=newNode;
    }
    temp->next=newNode;
    return head;
}
// thao tác xóa node trong danh sách liên kết đôi
// xóa node theo vị trí bất kì
Node* deletePosition(Node* head,int position) {
    // kiểm tra vị trí trước
    // nếu danh sách rỗng hoặc vị trí xóa âm thì dừng luôn
    if (head==NULL|| position<0) {
        printf(" vi tri khong hop le\n");
        return head;
    }
    if (position==0) {
        head=head->next;
        if (head!=NULL) {
            head->pre=NULL;
        }
        // giải phóng phần tử đầu
        free(head);
        return head;
    }
    //duyệt đến vị trí cần xóa
    int index=0;
    Node* temp=head;
    while(temp!=NULL && index<position) {
        temp=temp->next;
        index++;
    }
    // nếu vị trí nhập vào vượt khỏi danh sách thì temp sẽ là Null
    if (temp==NULL) {
        printf(" vi tri khong hop le\n");
        return head;
    }
    // cập nhật lại vị trí của node trước và node sau node cần xóa
    // liên kết node trước với node sau phần tử cần xóa
    if (temp->pre!=NULL) {
        temp->pre->next=temp->next;
    }
    // liên kết node sau phần tử cần xóa với node trước phần tử cần xóa
    if (temp->next!=NULL) {
        temp->next->pre=temp->pre;
    }
    free(temp);
    return head;
}
// tạo hàm hiển thị danh sách các node
void printList(Node* head) {
    Node* temp=head;
    while(temp!=NULL) {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main() {
    Node *head = NULL;
    head = insertAtHead(head,5);
    head = insertAtHead(head,4);
    head = insertAtHead(head,3);
    head = insertAtHead(head,2);
    head = insertAtHead(head,1);
    head = insertAtTail(head,6);
    head = insertAtTail(head,7);
    head = insertAtPosition(head, 20,2);
    head= deletePosition(head,2);
    printList(head);
}
