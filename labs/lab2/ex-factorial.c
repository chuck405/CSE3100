#include <stdio.h>

int factorial(int n) {
    int result = n;
    if (n == 1) 
        return result;
    result = factorial(n-1) * result;
}

int main() {
    int n;
    
    scanf("%d", &n);
    if (n < 0) 
        printf("Error: Please enter a non-negative integer.\n");
    else 
        printf("%d\n", factorial(n));

    return 0;
}