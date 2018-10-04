#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int *array = malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n; i++){
		array[i] = i;
	}
	for(i = 0; i < n; i++){
		printf("%d\n", array[i]);
	}
	if(array != NULL){
		free(array);
	}
}
