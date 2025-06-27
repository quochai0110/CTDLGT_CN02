#include <stdio.h>
int recurtion( int n) {
    if (n == 0) {
        return 0;
    }
    int result = n % 10 + recurtion(n / 10);
    return result;
}
int main() {
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    int result = recurtion(n);
    printf("The recursion is : %d\n", result);
}
