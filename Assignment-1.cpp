#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#define buffSize 5

struct
{
    pthread_mutex_t mutex;
    int buff[buffSize];
    int producedCount;
    int consumedCount;
} shared = { PTHREAD_MUTEX_INITIALIZER };

void *produce(void *arg);
void *consume(void *arg);

void *produce(void *arg)
{
    int itemNumber = 0;  //item for producer
    while(1)  //run forever
    {
        pthread_mutex_lock(&shared.mutex);

        //buffer is full then wait
        while(shared.producedCount - shared.consumedCount >= buffSize)
        {
            pthread_mutex_unlock(&shared.mutex);
            usleep(5000000);  //sleep
            pthread_mutex_lock(&shared.mutex);
        }

        //produce item
        int slot = shared.producedCount % buffSize;  //use buffer
        itemNumber++;
        shared.buff[slot] = itemNumber;
        shared.producedCount++;
        *((int *)arg) += 1;

        printf("Producer Thread %lu produced item %d at slot %d | Total in buffer: %d\n",
               pthread_self(), shared.buff[slot], slot,
               shared.producedCount - shared.consumedCount);

        pthread_mutex_unlock(&shared.mutex);
        usleep(10000000);  //sleep
    }
    return NULL;
}

void *consume(void *arg)
{
    while(1)  //run forever
    {
        pthread_mutex_lock(&shared.mutex);

        //wait if buffer is empty
        while(shared.consumedCount >= shared.producedCount)
        {
            pthread_mutex_unlock(&shared.mutex);
            usleep(5000000); //sleep
            pthread_mutex_lock(&shared.mutex);
        }

        //consume
        int slot = shared.consumedCount % buffSize;
        int item = shared.buff[slot];
        shared.consumedCount++;
        *((int *)arg) += 1;

        printf("Consumer Thread %lu consumed item %d from slot %d | Total in buffer: %d\n",
               pthread_self(), item, slot,
               shared.producedCount - shared.consumedCount);

        pthread_mutex_unlock(&shared.mutex);
        usleep(15000000);  //sleep
    }
    return NULL;
}

int main()
{
    int prodThreads = 0, consThreads = 0, i;

    printf("\nEnter the number of Producers: ");
    scanf("%d", &prodThreads);
    printf("\nEnter the number of Consumers: ");
    scanf("%d", &consThreads);

    int producerArr[prodThreads], consumerArr[consThreads];
    pthread_t producer[prodThreads], consumer[consThreads];

    for(i = 0; i < prodThreads; i++)
    {
        producerArr[i] = 0;
        pthread_create(&producer[i], NULL, produce, &producerArr[i]);
    }

    for(i = 0; i < consThreads; i++)
    {
        consumerArr[i] = 0;
        pthread_create(&consumer[i], NULL, consume, &consumerArr[i]);
    }

    for(i = 0; i < prodThreads; i++)
    {
        pthread_join(producer[i], NULL);
    }

    for(i = 0; i < consThreads; i++)
    {
        pthread_join(consumer[i], NULL);
    }

    return 0;
}
