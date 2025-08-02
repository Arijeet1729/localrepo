#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("This is parent. PID: %d\n", (int)getpid());

    int rc = fork();
    if (rc < 0) {
        // fork failed
        printf("Fork failed!\n");
        exit(1);
    } else if (rc == 0) {
        // child process
        printf("This is child. PID: %d\n", (int)getpid());
    } else {
        // parent process
        int rc_wiat=wait(NULL);
        printf("This is parent. My child is %d\n", rc);
    }

    printf("Who am I? PID: %d\n", (int)getpid());

    return 0;
}
