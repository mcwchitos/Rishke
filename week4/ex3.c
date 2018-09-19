#include <stdio.h>
#include <string.h>
int main(){
	char str[100];
	while(1){
		if(strcmp(str, "quit")){
			scanf("%s", str);
			system(str);
		}
		else
			break;
	}
	return 0;
}
