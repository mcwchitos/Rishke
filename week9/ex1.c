#include <stdio.h>
#include <stdlib.h>

typedef struct rate{
	int miss;
	int hit;
}Rate;

typedef struct frame{
	int value;
	int age;
	int used;
}Frame;

int findYoung(Frame *page, int m){
	int i;
	int min = page[0].age;
	int index = 0;
	for(i = 0; i < m; i++){
		if(page[i].age < min){
			min = page[i].age;
			index = i;
		}
	}
	return index;
}

void changeAge(Frame *page, int m){
	int i = 0;
	for(i = 0; i < m; i++){
		if(page[i].age > 0){
			page[i].age >> 1;
		}
	}
}

Rate countRate(int *arr, int n, int m){
	Rate result = {0, 0};
	Frame page[m];
	int max = 1 << 30;
	int i, j;
	for(i = 0; i < m; i++){
		page[i].age = -1;
		page[i].value = 0;
		page[i].used = 0;
	}
	for(i = 0; i < n; i++){
		int exist = 0;
		int index;
		for(j = 0; j < m; j++){
			if(arr[i] == page[j].value && page[j].used != 0){
				exist = 1;
				index = j;
				break;
			}
		}
		if(exist){
			changeAge(page, m);
			page[index].age += max;
			result.hit += 1;
		}else{
			int y = findYoung(page, m);
			changeAge(page, m);
			page[y].used = 1;
			page[y].value = arr[i];
			page[y].age = max;
			result.miss += 1;
		}
	}
	return result;
}

int main(){
	FILE *fp;
	fp = fopen("ex1.txt", "r");
	int i = 0;
	int n = 0;
	int array[2500];
	while(fscanf(fp, "%d", &array[i]) != EOF)
	{
		i++;
		n++;
	}
	fclose(fp);
	Rate res;

	int m = 10;
	res = countRate(array, n, m);
	printf("Hit/Miss rate: %d/%d\n", res.hit, res.miss);

	m = 50;
	res = countRate(array, n, m);
	printf("Hit/Miss rate: %d/%d\n", res.hit, res.miss);

	m = 100;
	res = countRate(array, n, m);
	printf("Hit/Miss rate: %d/%d\n", res.hit, res.miss);
	
	return 0;
}
