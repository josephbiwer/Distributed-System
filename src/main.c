#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	int fd[2];

	if(pipe(fd) < 0) {
		fprintf(stderr, "Issue creating pipe\n");
		exit(-1);
	}	


	int pid = fork();

	if(pid < 0) {
		printf("Issue starting child process\n");
		exit(-1);
	} else if (pid == 0) {
		char readfd[16];
		sprintf(readfd, "%d", fd[1]);
		printf("fd: %s\n", readfd);
		//execl("./test", "test", readfd, (char *)'\0');
		execl("./interface", "interface", readfd, (char *)0);
	} else {
		printf("parent process\n");
		char buffer[256];
		while(1) {
			if(read(fd[0], buffer, 256) > 0)
				printf("buffer from pipe: %s\n", buffer);
	 	}
		exit(0);
	}

	return 0;
}
