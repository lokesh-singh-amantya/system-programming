#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int main(int argc, char ** argv){
	char * to_exec = NULL;

	if(asprintf( &to_exec , "ls %s", argv[1]) == -1){
		perror("asprintf failed\n");
		return EXIT_FAILURE;
	}

	system(to_exec);
	return 0;
}
