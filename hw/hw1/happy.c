#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    printf("n = ");
    scanf("%d", &n);

    int m = n;
    //TODO
	//add code below
    while (n > 1) {
        int curr = n;
        n = 0;
        while (curr >= 10) {
            int last = curr % 10;
            curr /= 10;
            n += (last * last);
        }
        n += (curr * curr);

        printf("%d\n", n);
        if (n == 4) break;
    }
    

    if(n==1) printf("%d is a happy number.\n", m);
    else printf("%d is NOT a happy number.\n", m);
    return 0;
}
