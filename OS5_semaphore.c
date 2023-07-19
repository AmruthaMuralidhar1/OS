#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;   // Semaphore to track empty slots in the buffer
sem_t full;    // Semaphore to track filled slots in the buffer
sem_t mutex;   // Semaphore to provide mutual exclusion for buffer access

void *producer(void *arg) {
    int item = 1;
    while (1) {
        // Produce an item
        sleep(1);  // Simulate some time taken to produce the item
        printf("Producer produced item %d\n", item);

        // Wait for an empty slot in the buffer
        sem_wait(&empty);

        // Acquire the buffer mutex to add the item
        sem_wait(&mutex);

        // Add the item to the buffer
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;

        // Release the buffer mutex
        sem_post(&mutex);

        // Signal that there is a filled slot in the buffer
        sem_post(&full);

        item++;
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    while (1) {
        // Wait for a filled slot in the buffer
        sem_wait(&full);

        // Acquire the buffer mutex to remove the item
        sem_wait(&mutex);

        // Remove the item from the buffer
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;

        // Release the buffer mutex
        sem_post(&mutex);

        // Signal that there is an empty slot in the buffer
        sem_post(&empty);

        // Consume the item
        printf("Consumer consumed item %d\n", item);
        sleep(2);  // Simulate some time taken to consume the item
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish (This won't happen in this example as the threads run indefinitely)
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
