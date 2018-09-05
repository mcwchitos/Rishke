#include <stdio.h>
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void bubble_sort(int *arr, int n){
	int i, j;
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
int main(){
	int num;
	printf("Whire number of elements: ");
	scanf("%d", &num);
	int array[num];
	int i;
	for(i = 0; i < num; i++){
		scanf("%d", &array[i]);
	}
	bubble_sort(array, num);
	for(i = 0; i < num; i++){
		printf("%d", array[i]);
		printf(" ");
	}
	return 0;
}
