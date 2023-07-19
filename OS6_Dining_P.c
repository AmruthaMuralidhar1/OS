#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING_TIME 2
#define EATING_TIME 2

pthread_mutex_t forks[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void *philosopher_action(void *arg) {
    int philosopher_id = *(int *)arg;
    int left_fork = philosopher_id;
    int right_fork = (philosopher_id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Philosopher is thinking
        printf("Philosopher %d is thinking...\n", philosopher_id);
        sleep(THINKING_TIME);

        // Philosopher is hungry, wants to eat
        printf("Philosopher %d is hungry...\n", philosopher_id);

        // Try to acquire left fork
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d picked up left fork %d.\n", philosopher_id, left_fork);

        // Try to acquire right fork
        if (pthread_mutex_trylock(&forks[right_fork]) == 0) {
            printf("Philosopher %d picked up right fork %d.\n", philosopher_id, right_fork);

            // Philosopher is eating
            printf("Philosopher %d is eating...\n", philosopher_id);
            sleep(EATING_TIME);

            // Release the forks
            pthread_mutex_unlock(&forks[right_fork]);
            printf("Philosopher %d put down right fork %d.\n", philosopher_id, right_fork);
        } else {
            // Failed to acquire right fork, release the left fork
            pthread_mutex_unlock(&forks[left_fork]);
            printf("Philosopher %d couldn't get the right fork, put down left fork %d.\n", philosopher_id, left_fork);
        }

        // Put down left fork
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d put down left fork %d.\n", philosopher_id, left_fork);
    }

    pthread_exit(NULL);
}

int main() {
    int i;
    int philosopher_ids[NUM_PHILOSOPHERS];

    // Initialize mutexes for forks
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher_action, &philosopher_ids[i]);
    }

    // Wait for threads to finish (This won't happen in this example as the threads run indefinitely)
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
