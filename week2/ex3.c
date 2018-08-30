#include <stdio.h>

int main(){
    int k;
    scanf( "%d", &k);
    int i;
    for(i = 0; i < k; i++){
        int n = 2 * i + 1;
        int j;
        for(j = 0; j < k - i - 1; j++){
            printf(" ");
        }

        for(j = 0; j < n; j++){
            printf("*");
        }

        printf("\n");
    }
    return 0;
}