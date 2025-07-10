
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// khai báo cấu trúc ngăn xếp
#define MAX 100
#define LEN 100
typedef struct {
    // mảng để lưu các ký tự
    char data[MAX][LEN];// (3+5)
    // MAX: số lượng cac biểu thức có thể chứa trong stack
    // LEN : độ dài tối đa của mỗi biểu thức dạng chuỗi
    // chỉ số top
    int top;
}Stack;
// thao tác với ngăn xếp
// khởi tạo ngăn xếp
// sau khi khởi tạo đi thêm phần tử vào ngăn xếp, trước khi thêm kt ngăn xếp đã đầy hay chưa
// khi xóa phần tử trong ngăn xếp thì phải kiểm tra ngăn xếp có rỗng hay không

// HÀM KHỞI TẠO NGĂN XẾP
void initStack(Stack* s) {
    s->top = -1;// stack ban đầu rỗng
}
// HAM ĐI THÊM PHẦN TỬ VÀO NGĂN XẾP
void pushElement(Stack* s, char* str) {
    // trước khi thêm kiểm tra stack có đầy hay không
    if (s->top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    // tăng giá trị top lên 1
    s->top++;
    // sao chép chuỗi vào trong stack
    strcpy(s->data[s->top], str);

}
// HÀM LAY PHAN TU RA
char* popElement(Stack* s) {
    // kiểm tra nếu stack không có phần tử thì không xóa được
    if (s->top == -1) {
        printf("Stack is empty\n");
        return "";
    }
    // lấy phan tử ra sau đó giảm top 1 đơn vị
    return s->data[s->top--];
}
// TẠO HÀM ĐỂ CHUYỂN CÁC KÝ TU HẬU TỐ SANG TRUNG TỐ
char* postfixInFix(char* postfix) {
    Stack s;
    initStack(&s);
    //duyệt từng ký tự trong mảng ký tự postfix
    for (int i = 0; postfix[i]!='\0'; i++) {
        char c = postfix[i];
        // kiểm tra từng ký tự
        // nếu là số đưa vào stack
        if (isdigit(c)) {
            char temp[]={c,'\0'};
            pushElement(&s, temp);
        }else if (c=='+' || c =='-' || c=='*' || c=='/') {
            // lấy toán hạng 1 và toán hạng 2 ra gộp lại
            char* element1= popElement(&s);
            char* element2 = popElement(&s);
            // tạo mảng để lưu các phan tử khi gộp lại
            char temp[LEN*2];
            snprintf(temp, LEN*2, "(%s%c%s)", element2,c, element1);
            // sau khi gộp lại thì lại push stack
            pushElement(&s, temp);
        }
        // nếu là toán tử pop toán hạng 1 và toán hạng 2 gộp lại
    }
    return popElement(&s);
}
int main() {
    char str[MAX];
    printf("moi ban nhap bieu thuc hau to\n");
    fgets(str, MAX, stdin);
    // str[strlen(str) - 1] = '\0';
    str[strcspn(str, "\n")] = '\0';// xóa ký tự \n
    char* result = postfixInFix(str);
    printf("%s\n", result);

}
