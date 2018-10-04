#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int *array = malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n; i++){
		array[i] = i;
	}
	int m;
	scanf("%d", &m);
	array = realloc(array, m * sizeof(int));
	for (i = 0; i < m; i++){
		printf("%d\n", array[i]);
	}
}
