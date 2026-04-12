#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define NAMEDPIPE_NAME "/tmp/my_named_pipe"
#define BUF_SIZE 50

int main() {
    if (mkfifo(NAMEDPIPE_NAME, 0777)) {
        perror("mkfifo");
        return 1;
    }
    puts("create file");

    int fd = open(NAMEDPIPE_NAME, O_RDONLY);
    if (fd <= 0 ) {
        perror("open");
        return 1;
    }
    puts("open file");

    char buf[BUF_SIZE];
    do {
        memset(buf, '\0', sizeof(buf));
        int len = read(fd, buf, sizeof(buf));
        if (len <= 0) {
            perror("read");
            close(fd);
            remove(NAMEDPIPE_NAME);
            return 1;
        }
        printf("read msg: %s", buf);
    } while (1);

    return 0;
}