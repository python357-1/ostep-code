#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/*
	Write a program that creates a child process, and then in the child
	closes standard output (STDOUT FILENO). What happens if the child
	calls printf() to print some output after closing the descriptor?

	it seems as though printf thinks that it has still succeeded, because
	printf should return a negative value if it failed and a positive value
	if it succeeded, with the positive value being the number of characters.
	as the program currently stands with the child running printf on 
	"child speaking", printf returns 14, but does not itself print anything
	to the console.
*/
int main() {

	int f = fork();

	if (f < 0) {
		printf("fork failed: %d", f);
	} else if (f == 0) {
		close(STDOUT_FILENO);
		int printstatus = printf("child speaking");
		return printstatus;
	} else {
		int status;
		waitpid(f, &status, 0);
		if (WIFEXITED(status)) {
			printf("return value: %d", WEXITSTATUS(status));
		}
	}
}
