#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();
    if (0 > pid) {
        perror("fork");
        return 1;
    }

    if (0 == pid) {
        // child - read
        close(fd[1]);

        char buf[100];
        read(fd[0], buf, sizeof(buf));
        printf("child read: %s\n", buf);
        
        close(fd[0]);
    } else if (0 < pid) {
        // parent - write
        close(fd[0]);

        char msg[] = "hi from parent!";
        write(fd[1], msg, strlen(msg));

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}