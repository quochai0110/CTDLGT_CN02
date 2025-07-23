#include <stdio.h>

void printAdjacencyMatrix(int matrix[7][7], int size) {// size la so luong dinh
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
// Hiển thị kết nối giữa các đỉnh
void printConnect(int matrix[7][7], char vertices[7],int size){
    printf("\nConnectivity Matrix:\n");
    for (int i = 0; i < size; i++) {
        printf("%c: ", vertices[i]);// mục đích hiển thị A, B, C, D, E, F, G
        for (int j = 0; j < size; j++) {
            // kết nối
            if (matrix[i][j]==1) {
                printf("%c ", vertices[j]);// C D E
                // B: C F
            }
        }
        printf("\n");
    }
}
int main() {
    char vertexData[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int adjacencyMatrix[7][7] = {
        {0, 0, 1, 1, 1, 0, 0}, // Edges for A
        {0, 0, 1, 0, 0, 1, 0}, // Edges for B
        {1, 1, 0, 0, 1, 1, 1}, // Edges for C
        {1, 0, 0, 0, 0, 0, 0}, // Edges for D
        {1, 0, 1, 0, 0, 0, 0}, //Edges E
        {0, 1, 1, 0, 0, 0, 0}, // edges F
        {0, 0, 1, 0, 0, 0, 0} // Edges G
    };

    printf("vertexData: ");
    for (int i = 0; i < 7; i++) {
        printf("%c ", vertexData[i]);
    }
    printf("\n");

    printAdjacencyMatrix(adjacencyMatrix, 7);
    printConnect(adjacencyMatrix, vertexData, 7);

    return 0;
}

//C
