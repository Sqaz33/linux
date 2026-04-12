#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>

#define SHM_OBJ "my_shm_obj"
#define SHM_OBJ_SZ 51

int main() {
    int fd = shm_open(SHM_OBJ, O_CREAT|O_RDWR, 0777);
    if (-1 == fd) {
        perror("shm_open");
        return 1;
    }

    char* addr = mmap(NULL, SHM_OBJ_SZ, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    if ((char*) -1 == addr) {
        perror("mmap");
        return -1;
    }

    printf("proc2.c - msg from proc1.c: %s\n", addr);

    munmap(addr, SHM_OBJ_SZ);
    close(fd);
    shm_unlink(SHM_OBJ);
}   