#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

pid_t child;

void cleanup(int signal){
	signal = signal;
	int status;
//	waitpid(child, &status, 0);
	while( waitpid( (pid_t) (-1), 0, WNOHANG) > 0 ){};
	write(1, "cleanup!", 9);
}

int main(){
// Register signal handler BEFORE the child can finish
	signal(SIGCHLD, cleanup);  // or better - sigaction

	child = fork();

	if(child == -1) exit(EXIT_FAILURE);

	if (child == 0){
		execl("/bin/ls", "/bin/ls", ".", (char*) NULL);
	} else {
		sleep(1); // we can see the cleanup logs
			// will be affected by an incoming signal (here SIGCHLD)
		puts("Parent is done");
	}

	return 0;
}
