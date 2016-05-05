#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_err.h"
#define N 5 //No. of reader
#define M 5 //No. of reading and writing

pthread_rwlock_t lock; //it's mean writer can writing

int readCount = 0;

void* reader(void *arg)
{
    int n = M;
    int id = (int)arg;
    while (n--)
    {
        sleep( rand() % 3);
        pthread_rwlock_rdlock(&lock);
        printf("reader %d is reading\n", id);
        sleep( rand() % 3);

        pthread_rwlock_unlock(&lock);
        printf("reader %d is leaving\n", id);
    }
    printf("----reader %d has done----\n", (int)arg);
}

void* writer(void *arg)
{
    int n = M;
    while (n--)
    {
        sleep( rand() % 3);
        pthread_rwlock_wrlock(&lock);
        printf("\twriter is writing\n");
        sleep( rand() % 3);
        pthread_rwlock_unlock(&lock);
        printf("\twriter is leaving\n");
    }
    printf("----writer has done----\n");
}

int main(int argc, const char *argv[])
{
    int err;
    pthread_t tid[N], writerTid;
    int i;

    err = pthread_create(&writerTid, NULL, writer, (void *)NULL);
    if (err != 0)
    {
        err_quit("can't create process for writer");

    }

    pthread_rwlock_init(&lock, NULL);
    for (i = 0; i < N; i++)
    {
        err = pthread_create(&tid[i], NULL, reader, (void *)(i+1));
        if (err != 0)
        {
            err_quit("can't create process for reader");
        }
    }
    pause();
    pthread_rwlock_destroy(&lock);
    return 0;
}
