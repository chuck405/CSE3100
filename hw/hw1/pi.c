#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("n = ");
    scanf("%d", &n);
   
    double pi = 0.0;

    for (i=0; i<=n; i++) {   
        double curr = (4.0/(8*i+1)) - (2.0/(8*i+4)) - (1.0/(8*i+5)) - (1.0/(8*i+6));
        for (int j=1; j<=i; j++) curr /= 16;    
        pi += curr;
    }

    printf("PI = %.10f\n", pi);
    return 0;
}