#include <stdio.h>
#include <stdlib.h>

// DANH SÁCH KỀ
typedef struct Node {
    int vertex;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}
Node* adjacentNode[100];
void addEgde (int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjacentNode[u];
    adjacentNode[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjacentNode[v];
    adjacentNode[v] = newNode;
}

void printMatrix (int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = adjacentNode[i];
        printf("%d ", temp->vertex);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n,u,v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 0; i < 6; i++) {
        printf("nhap gia tri canh lien ket: ");
        scanf("%d %d", &u,&v);
        addEgde(u, v);
    }
    printf("\n");
    printMatrix(n);
}