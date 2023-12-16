#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* print out an error message and exit */
void my_error(char *s)
{
    perror(s);
    exit(1);
}

/* Concatnate two strings.
 * Dynamically allocate space for the result.
 * Return the address of the result.
 */
char *my_strcat(char *s1, char *s2)
{
    char *s3 = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
    if (s3 == NULL) 
        my_error("memory allocation failed");

    int i = 0, j = 0;
    while (i < strlen(s1)) {
        s3[i] = *(s1 + i);
        i++;
    }
    while (j <= strlen(s2)) {
        s3[i+j] = *(s2 + j);
        j++;
    }
    return s3;
}

int main(int argc, char *argv[])
{
    char *s;

    s = my_strcat("", argv[0]);

    for (int i = 1; i < argc; i ++) {
        char *curr = my_strcat(s, argv[i]);
        free(s);
        s = curr;
    }

    printf("%s\n", s);
    free(s);
    return 0;
}