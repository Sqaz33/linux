#include <fcntl.h>
#include <stdio.h>
#include <semaphore.h>

#define SEM_NAME "/my_sem"

int main(int argc, char**) {
    sem_t* sem;

    if (2 == argc) {
        if ((sem = sem_open(SEM_NAME, 0)) == SEM_FAILED) {
            perror("sem_open");
            return 1;
        }
        sem_post(sem);
        perror("sem_post");
        return 0;
    }

    if ((sem = sem_open(SEM_NAME, O_CREAT, 0777, 0)) == SEM_FAILED) {
        perror("sem_open");
        return 1;
    }

    if (sem_wait(sem) < 0) {
        perror("sem_wait");
    }

    if (sem_close(sem) < 0) {
        perror("sem_close");
    }
}
