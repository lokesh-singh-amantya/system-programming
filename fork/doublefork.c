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

/*

The first child then closes the file stream to prevent the file descriptor from being shared with its own child. The second fork creates a grandchild that runs independently and asynchronously without access to the file, allowing safe background work. The parent waits only for the first child, leaving the grandchild detached and running separately.

*/
		
		pid_t child = fork();
		if(child == 0){				// child
			fclose(file);
			if (fork() == 0){		// grandchild
				// Do async work
				// Safe exit
				exit(0);
			}
			exit(0);
		}
	}	
	waitpid(child, NULL, 0); // only waits for the child
	return 0;
}
