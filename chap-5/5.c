#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
	int f = fork();

	if (f < 0) {
		printf("fork failed: %d", f);
	} else if (f == 0) {
		int x = wait(NULL);
		printf("child (%d): x = %d", getpid(), x);
	} else {
		int x = wait(NULL);
		printf("parent (%d): x = %d", getpid(), x);
	}
}
