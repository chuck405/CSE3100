#include <stdio.h>

long catalan_number(int n) {
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;
    return (4*n-2) * catalan_number(n-1) / (n+1);
}

int main(void) {
    int n;

    while (scanf("%d", &n) == 1) {
        if (n < 0) 
            printf("C(%2d) is not defined.\n", n);
        else 
            printf("C(%2d)=%18ld\n", n, catalan_number(n));
    }
    return 0;
}