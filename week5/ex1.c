#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *funct(int n){
    printf("Thread #%d\n", n);
    printf("Hello from the other siiiiiiide %d\n", n);
    pthread_exit(0);
}

int main(){
    int n, i;
    scanf("%d", &n);
    pthread_t thid[n];
    printf("Parallel solution\n");
    for(i = 0; i < n; i++){
        if(pthread_create(&thid[i], NULL, funct, i + 1) != 0){
            perror("pthread_create() error\n");
            exit(1);
        }
        else {
            printf("Thread #%d created\n", i + 1);
        }
    }
    for(i = 0; i < n; i++){
        if(pthread_join(thid[i], NULL) != 0){
            perror("pthread_create error\n");
            exit(3);
        }
    }
    printf("Sequential solution\n");
    for(i = 0; i < n; i++){
        if(pthread_create(&thid[i], NULL, funct, i + 1) != 0){
            perror("pthread_create() error\n");
            exit(1);
        }
        else {
            printf("Thread #%d created\n", i + 1);
        }
        if(pthread_join(thid[i], NULL) != 0){
            perror("pthread_create error\n");
            exit(3);
        }
    }
    return 0;
}