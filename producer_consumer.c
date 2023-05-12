#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#define buf_size 3
int buf[buf_size];
int buf_index, p_index = -1, c_index = -1;
int p[100], c[100];
sem_t empty;
sem_t full;
sem_t mutex;

int removei()
{
    int item = buf[--buf_index];
    printf("Item %c has consumed by consumer\n", item+64);
    return item;
}
void inserti(int item)
{
    buf[buf_index++] = item;
    printf("Item %c has produced by producer\n", item+64);
}
void *producer(void *arg)
{
    int item;
    while (1)
    {
        item = rand() % 10;
        sem_wait(&empty); 
        while (p_index != -1)
        {
            sem_wait(&mutex);
            buf[buf_index++] = p[p_index];
            printf("Producer added item from blocked %d\n", p[p_index]);
            p_index--;
            sem_post(&mutex);
        }
        sem_wait(&mutex);
        inserti(item); 
        sem_post(&mutex);
        sem_post(&full); 
        if (buf_index == buf_size - 1)
        {
            printf("buffer full.Process blocked\n");
            p_index++;
            p[p_index] = item;
        }
        sleep(rand() % 3);
    }
}
void *consumer(void *arg)
{
    int item;
    while (1)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        item = removei();
        sem_post(&mutex);  
        sem_post(&empty);
        sleep(rand() % 3);
    }
}
int main(int argc, char *argv[])
{
    sem_init(&empty, 0, buf_size);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);
    buf_index = 0;
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;
}