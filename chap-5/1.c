#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main(int argv, char* argc[]) {
	int x = 100;
	int file = open("testfile.txt", O_RDWR | O_CREAT);
	int f = fork();

	if (f < 0) {
		printf("fork failed: %d\n", errno);
		exit(1);
	} else if (f == 0) { //child
		char* message = "child message";
		write(file, message, strlen(message));
	} else { //parent
		char* message = "parent message";
		write(file, message, strlen(message));
	}
}
