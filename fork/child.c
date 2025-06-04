#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	
	pid_t id; int status;

	while(--argc && (id=fork())){
		waitpid(id, &status, 0); /* Wait for child*/
		printf("[PID %d ] status %d\n", getpid(), status);
	}

	printf("[PID %d] %d : %s\n", getpid() ,argc, argv[argc]);

}
