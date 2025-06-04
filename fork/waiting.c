#include <stdio.h>
#include <unistd.h>	// fork(), sleep(), pid_t
#include <stdlib.h>	// exit()
#include <sys/wait.h>	// waitpid(), WIFEXITED(status), WEXISTATUS(status)

int main(){

	pid_t child = fork();
	int status; // contains more than just the exit status from the process

	if ( child == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child > 0){
		// parent will wait for child to finish
		pid_t pid = waitpid(child, &status, 0);

		if (pid != -1 && WIFEXITED(status)){
			int exit_status = WEXITSTATUS(status);
			printf("Child exited with code %d\n", exit_status );
		}
	} else {

		execl("/bin/ls", "/bin/ls", ".", (char *) NULL); // "ls ."
		// excel never returns if success
		// below lines only rins of execl() fails
		perror("execl failed");
		exit(EXIT_FAILURE);
	}

	return 0;
}

