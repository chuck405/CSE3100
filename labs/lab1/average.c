// Only this line of comment is provided 

#include <stdio.h>

int main(void) {
    int n = 0;
    double x = 0;
    double total, average = 0;
    
    while (scanf("%lf", &x) == 1) {
        n += 1;
        total += x;
        average = total / n;
        printf("Total=%f Average=%f\n", total, average);
    }
}