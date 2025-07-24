#include <stdio.h>

#define SIZE 3  // Số đỉnh của đồ thị

// Hàm in ma trận kề
void printMatrix(int graph[SIZE][SIZE]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Hàm thêm cạnh giữa hai node (đồ thị vô hướng)
void addEdge(int graph[SIZE][SIZE], int node1, int node2) {
    graph[node1][node2] = 1;
    graph[node2][node1] = 1;  // Vì là đồ thị vô hướng
}

int main() {
    // Khởi tạo ma trận với tất cả phần tử là 0 (chưa có cạnh)
    int graph[SIZE][SIZE] = {0};

    // In ma trận ban đầu
    printMatrix(graph);

    // Thêm cạnh giữa node 0 và 1
    addEdge(graph, 0, 1);

    // Thêm cạnh giữa node 1 và 2
    addEdge(graph, 1, 2);

    // In ma trận sau khi thêm cạnh
    printf("\nAfter adding edges:\n");
    printMatrix(graph);

    return 0;
}
