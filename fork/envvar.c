#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char * home = getenv("HOME");
	
	printf("env var val = %s\n", home);

	return 0;
}
