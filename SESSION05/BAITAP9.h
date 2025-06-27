//
// Created by DELL on 6/27/2025.
//
#include <stdio.h>
int recursion(int row, int col, int i, int j) {
     if (i == row && j == col) {
         return 1;
     }
    if (i>row-1 || j>col-1) {
        return 0;
    }
    return recursion(row, col, i+1, j)+ recursion(row, col, i, j+1);

}
int main() {

    int row;
    int col;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    int result = recursion(row, col, 0, 0);
    printf("Result: %d\n", result);

}