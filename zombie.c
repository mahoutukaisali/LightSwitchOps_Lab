#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    pid = fork();
    if (pid == 0) { // child process
        execl("/bin/sleep", "sleep", "5", NULL);
    } else { // parent process
        int status;

        sleep(180);
        exit(0);

        waitpid(pid, &status, 0);
        printf("PID %d has been finished; exit status: %d", pid, status);
        exit(0);
    }
}