#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
	close(1);

	// gets available lower fd , here , 1
	open("log.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);

	if(-1 == puts("Captain's log\n")){
		perror("error");
	}

	chdir("/usr/include");
	fflush(stdout);
	execl("/bin/ls", "/bin/ls", ".", (char*) NULL);
	perror("exec failed");

	return 0;
}
