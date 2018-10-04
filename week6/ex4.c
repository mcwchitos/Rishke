#include  <stdio.h>

void *MyFunct(void *ptr, size_t size){
	if(size == 0){
		free(ptr);
		return NULL;
	}
	else if(!ptr){
		return malloc(size);
	}
	void* newptr = malloc(size);
	memcpy(newptr, ptr, size);
	free(ptr);
	return newptr;
}

int main(){
	int n;
	scanf("%d", &n);
	int* arr = malloc(n * sizeof(int));
	int i;
	for(i = 0; i < n; i++){
		arr[i] = i;
	}
	for(i = 0; i < n; i++){
		printf("%d\n", arr[i]);
	}
	int m;
	scanf("%d", &m);
	arr = MyFunct(arr, m * sizeof(int));
	for(i = 0; i < m; i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}
