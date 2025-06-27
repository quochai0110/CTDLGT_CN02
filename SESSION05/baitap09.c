//
// Created by DELL on 6/27/2025.
//
#include <stdio.h>
int recursion(int row, int col, int i, int j, int backRow,int backCol) {
    if (i == row-1 && j == col-1) {
        return 1;
    }
    if (i>row-1 || j>col-1 ) {
        return 0;
    }
    if (backCol==j&&backRow==i) {
        return 0;
    }
    return recursion(row, col, i+1, j, backRow,backCol)+ recursion(row, col, i, j+1,backRow, backCol);
}
int main() {

    int row;
    int col;
    int backedRow;
    int backedCol;
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    printf("Enter number of backed row: ");
    scanf("%d", &backedRow);
    printf("Enter number of backed col: ");
    scanf("%d", &backedCol);
    int result = recursion(row, col, 0, 0, backedRow, backedCol);
    printf("Result: %d\n", result);




}