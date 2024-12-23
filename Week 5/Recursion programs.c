#include<stdio.h>
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n));
}
#include<stdio.h>
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
void main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Fibonacci of %d is %d\n", n, fibonacci(n));
}
#include<stdio.h>
#include <stdio.h>

void hanoi(int n, char S, char D, char T) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", S, D);
        return;
    }
    hanoi(n - 1, S, T, D);
    printf("Move disk %d from %c to %c\n", n, S, D);
    hanoi(n - 1, T, D, S);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'S', 'D', 'T');
    return 0;
}
