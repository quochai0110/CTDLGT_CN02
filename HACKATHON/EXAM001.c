//
// Created by DELL on 7/18/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Bước 1: tạo cấu trúc dữ liệu
 // Cấu trúc 1 nhiệm vụ
 typedef struct Task {
  int id ;
  char title[100];
  int priority;
  char deadline[100];
 }Task;
 // Danh sách liên kết đơn
 typedef struct TaskNode {

    Task data;
    struct TaskNode* next;
 }TaskNode;
 // Danh sách liên kết đôi
 typedef  struct CompletedTaskNode {
  Task data;
  struct CompletedTaskNode* next;
  struct CompletedTaskNode* prev;
 }CompletedTaskNode;
// Bước 2: tạo các hàm
 // Hàm thêm nhiệm vụ
TaskNode* addTask(TaskNode* head) {
 Task newTask;
 printf("Vui long nhap id :");
 scanf("%d",&newTask.id);
 getchar();
 printf("vui long nhap title");
 fgets(newTask.title,100,stdin);
 newTask.title[strlen(newTask.title)-1] = '\0';
 printf("vui long nhap priority");
 scanf("%d",&newTask.priority);
 getchar();
 printf("vui long nhap deadline");
 fgets(newTask.deadline,100,stdin);
 newTask.deadline[strlen(newTask.deadline)-1] = '\0';
 TaskNode* newTaskNode = (TaskNode*)malloc(sizeof(TaskNode));
 newTaskNode->data = newTask;
 newTaskNode->next = head;
 head=newTaskNode;
 return head;
}
 // Hàm hiển thị nhiệm vụ
void printTask(TaskNode* head) {
 if (head == NULL) {
  printf("trong danh sach khong co han tu nao ");
  return;
 }
 TaskNode* curr =head;
 while (curr != NULL) {
  printf("ID :%d - Title :%s - priority :%d - dealine : %s \n",curr->data.id,curr->data.title,curr->data.priority,curr->data.deadline);
  curr = curr->next;
 }
}
 // Hàm xóa nhiệm vụ
TaskNode* deleteTask(TaskNode* head,int id) {
 TaskNode* curr = head;
 TaskNode* prev = NULL;
 if (curr == NULL) {
  printf("khong co phan tu nao");
  return NULL;
 }
 while (curr != NULL) {
  if (curr->data.id == id) {
   // 1.Phan tu xoa la phan tu dau tien
   if (prev) {
    prev->next =curr->next;
   }else {
    head = curr->next;
    printf("da xoa phan tu dau ");
    free(curr);
    return head;
   }
  }
  // 2. Phan tu xoa khong phai phan tu dau tien
  prev = curr;
  curr = curr->next;
 }
 printf("khong co phan tu trung id");
 return head;
}
 // Hàm cập nhật nhiệm vụ
void updateTask(TaskNode* head,int id) {
 TaskNode* curr = head;
 if (curr == NULL) {
  printf("khong co phan tu nao");
  return;
 }
 while (curr) {
  if (curr->data.id == id) {
   printf("vui long nhap title moi");
   fgets(curr->data.title,100,stdin);
   curr->data.title[strlen(curr->data.title)-1] = '\0';
   printf("vui long nhap priority moi");
   scanf("%d",&curr->data.priority);
   getchar();
   printf("vui long nhap deadline moi");
   fgets(curr->data.deadline,100,stdin);
   curr->data.deadline[strlen(curr->data.deadline)-1] = '\0';

   return;
  }
  curr = curr->next;
 }
 printf("khong co phan tu nao can xoa");
 return;

}
 // Hàm sắp xếp nhiệm vụ theo độ ưu tiên
 // Hàm đánh dấu nhiệm vụ đã hoàn thành ( chuyển từ danh sách đơn sang đôi)
void completeTask(TaskNode* head,int id,CompletedTaskNode* head2) {
 TaskNode* curr = head;
 TaskNode* prev = NULL;
 if (curr == NULL) {
  printf("khong co nhiem vu nao");
  return;
 }
 while (curr) {
  if (curr->data.id == id) {
    // tạo node
    // đưa sang liên kết đôi
    // nhớ kiểm tra trong đôi có phần tử nào hay không, nếu chưa có gán phần tử đầu
   // nếu có rồi gán lại newNode pre->NULL, next -> current
   // current-> prev

   // node trong liên kết đơn
   // kiểm tra có phải node đầu hay không, nếu là node đầu xóa : head= curr->next
   // nếu không phải node đầu tiên: pre-next= current-> next
   // nhớ free ( current)
  }
  prev = curr;
  curr = curr->next;

 }


}
 // Hàm tìm kiếm nhiệm vụ theo tên nhiệm vụ
void findTask(TaskNode* head,char* task) {
 TaskNode* curr = head;
 int flag = 0;
 if (curr == NULL) {
  printf("khong co phan tu nao");
  return;
 }
 while (curr) {
  if (strstr(curr->data.title,task)) {
   printf("ID :%d - Title :%s - priority :%d - dealine : %s \n",curr->data.id,curr->data.title,curr->data.priority,curr->data.deadline);
   flag = 1;
  }
  curr = curr->next;

 }
 if (flag == 0) {
  printf("khong tim thay nhiem vu nao");
  return;
 }
}
// Bước 3: tạo menu lựa chọn
// Bước 4: chạy kiểm thử
int main() {
 TaskNode* taskList = NULL;
 CompletedTaskNode* completedTaskList = NULL;

 int choice;
 do {
  printf("\n MENU\n");
  printf("1. Add task\n");
  printf("2. print task\n");
  printf("3. delete task\n");
  printf("4. update task\n");
  printf("5.Find task\n");

  printf("Vui long chon :");
  scanf("%d",&choice);
  getchar();
  switch(choice) {
   case 1:
    taskList = addTask(taskList);
    break;
   case 2:
    printTask(taskList);
    break;
   case 3:
    int id ;
    printf("vui long nhap id can xoa");
    scanf("%d",&id);
    getchar();
    taskList = deleteTask(taskList,id);
    break;
   case 4:
    printf("vui long nhap id can cap nhat");
    scanf("%d",&id);
    getchar();
    updateTask(taskList,id);
    break;
   case 5:
    char task[100];
    printf("vui long nhap title can tim kiem");
    fgets(task,100,stdin);
    task[strlen(task)-1] = '\0';
    findTask(taskList,task);
    break;
  }
 }while (choice != 8);



}