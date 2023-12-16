#include <stdio.h>

int sum(int n, int* arr)
{
    int i, sum = 0;
    for(i = 0; i <= n; i++)
        sum += *(arr + i);
    return sum;
}

void fillSquares(int n, int* arr)
{
    int i;
    for(i = 0; i <= n; i++)
        *(arr + i) = i*i;
}

int main(int argc, char* argv[])
{
    int n, total;

    if(argc < 2) {
        printf("usage: ./squares n\n");
        return 1;
    }

    n = atoi(argv[1]);
    if (n <= 0) {
        printf("n must be positive.");
        return 1;
    }
    int* arr = malloc((n+1) * sizeof(int));

    fillSquares(n, arr);
    total = sum(n, arr);
    printf("total: %d\n", total);
    free(arr);
    return 0;
}