#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char ** argv)
{
    pid_t child;
    int exitStatus;

    // at least, there should be 3 arguments
    // 2 for the first command, and the rest for the second command
    if (argc < 4) {
        fprintf(stderr, "Usage: %s cmd1 cmd1_arg cmd2 [cmd2_args ..]\n", argv[0]);
        return 1;
    }

    // TODO
    pid_t grandchild;
    child = fork();
    if (child == -1) perror("fork()");
    else if (child == 0) {
        grandchild = fork();
        if (grandchild == -1) perror("fork()");
        else if (grandchild == 0) {
            if (execlp(argv[0], argv[1], argv[2], NULL) == -1) perror("execlp()");
            exit(0);
        }
        else{
            waitpid(grandchild, &exitStatus, 0);
            if (execvp(argv[3], &argv[3]) == -1) perror("execvp()");
            exit(0);
        }
    }
    
    else {
        waitpid(child, &exitStatus, 0);
        printf("exited=%d exitstatus=%d\n", WIFEXITED(exitStatus), WEXITSTATUS(exitStatus));
    }
    return 0;
}