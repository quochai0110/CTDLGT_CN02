//
// Created by DELL on 7/11/2025.
// TẠO CẤU TRÚC
#include <stdio.h>
// CẤU TRÚC KHÓA HỌC

typedef struct {

    int id;
    char title[100];
    int credit;
}Course;

// CẤU TRÚC DANH SÁCH LIÊN KẾT ĐƠN
typedef struct Node {
    Course course;
    struct Node *next;
}Node;

// CẤU TRÚC DANH SÁCH LIÊN KẾT ĐÔI
typedef struct DoubleNode {
    Course course;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;

int main() {

}
