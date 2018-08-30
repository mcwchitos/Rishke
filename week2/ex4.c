#include <stdio.h>

void swap(int *a, int *b){
    int third = *a;
    *a = *b;
    *b = third;
}

int main(){
    int a;
    scanf( "%d", &a);
    int b;
    scanf( "%d", &b);
    swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}