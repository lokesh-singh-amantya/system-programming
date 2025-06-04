#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

extern char ** environ;


int main(int argc, char ** argv){
	
	pid_t child = fork();

	if(child == -1) { return EXIT_FAILURE; }

	if (child) {
		int status;
		waitpid(child, &status, 0);
		return EXIT_SUCCESS;
	} else {
		// Remember first arg is the program name
		// Last arg must be a char pointer to NULL	
		execl("/bin/ls","/bin/ls", "-alh", (char*) NULL);

		perror("exec failed!");
	}

	return 0;
}
