#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	
	pid_t child_pid = fork();
	int status;

	if (child_pid < 0){
		exit(1);
	} else if ( child_pid > 0){
		waitpid(child_pid, &status, 0);
		if( WIFEXITED(status)){
			printf("child exit status = %d\n", WEXITSTATUS(status));
		}	

	} else { // child process will execute below lines

// correct the execl command to print the correct output
		execl("/bi/ls", "/bn/ls", NULL);
		exit(1) ; 
	}

	return 0;
}

