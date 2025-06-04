#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv){

	// call argc amount of child processes
	while(--argc && !fork());
	
	// child process will execute these lines
	int val = atoi(argv[argc]);
	sleep(val);
	printf("%d\n", val);
	return 0;
}
