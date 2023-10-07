#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main() {
	int pipe_ends[2];
	int pipe_result = pipe(pipe_ends);
	if (pipe_result != 0) {
		perror("pipe: ");
	}
	int childone_pid = fork();
	int childtwo_pid = 0;

	if (childone_pid > 0) {
		childtwo_pid = fork();
	}


	if (childone_pid == 0) {
		close(STDOUT_FILENO);
		dup(pipe_ends[1]);
		close(pipe_ends[0]);

		printf("test");
	}

	if (childtwo_pid == 0) {
		close(STDIN_FILENO);
		dup(pipe_ends[0]);
		close(pipe_ends[1]);

		char buf[6] = {0};
		read(STDIN_FILENO, &buf, 5);
		printf("%s\n", buf);
	}
}
