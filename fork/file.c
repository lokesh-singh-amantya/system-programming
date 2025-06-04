#include <stdio.h>
#include <stdlib.h>     
#include <unistd.h>     
#include <sys/wait.h>  

int main(){

	size_t buffer_cap = 0;
	char * buffer = NULL;

	ssize_t nread;

	FILE * file = fopen("test.txt", "r");
	int count = 0;

	// nread = read number of chars including newline character
	while((nread = getline(&buffer, &buffer_cap, file)) != -1){
		printf("%s", buffer);
		// discards the remaining buffer
		fflush(file);
		fflush(stdout);
		if(fork() == 0){
			exit(0);
		}
	}

	// wait for all child processes to complete
	while (wait(NULL) > 0);

	free(buffer);
	fclose(file);
	return 0;
}
