#include <stdio.h>

int main(){
	int n = 100;
	int PID;
	PID = fork();
	if(PID > 0)
		printf("Hello from PARENT: %d\n", getpid() - n);
	else if (PID == 0)
		printf("Hello from CHILD: %d\n", getpid() - n);
	return 0;
}
