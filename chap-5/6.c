#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/*
 * 
Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be useful?


because wait() only waits until any child is finished, waitpid() would be used in cases where you want the value from a specific child process.



*/

int main() {
	int f = fork();

	if (f < 0) {
		printf("fork failed: %d", f);
	} else if (f == 0) {
		int x = wait(NULL);
		printf("child (%d): x = %d", getpid(), x);
	} else {
		int x = waitpid(f, NULL, 0);
		printf("parent (%d): x = %d", getpid(), x);
	}
}
