#include <stdio.h>

int main(void)
{
    int i = 2, sum = 0;
    printf("Hello, World!\n");
    while (i < 200)
        {
            sum += i;
            i += 2;
        }
    printf("%d\n", sum);
    return 0;
}