#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
/*
 * 	Write a program that calls fork() and then calls some form of
	exec() to run the program /bin/ls. See if you can try all of the
	variants of exec(), including (on Linux) execl(), execle(),
	execlp(), execv(), execvp(), and execvpe(). Why do
	you think there are so many variants of the same basic call?

	there are different versions of exec() because they do different things. from the linux manual (https://man7.org/linux/man-pages/man3/exec.3.html):

	- execl, execlp, execle 	(l): take multiple parameters that are pointers to null terminated strings that are the arguments for the new program
	
	- execv, execvp, execvpe 	(v): take a single parameter that is an array of pointers to null terminated strings that are all arguments for the new program
	
	- execle, execvpe 			(e): take a single parameter, envp, that is an array of key-value pairs for the environment of the new program. all others use the environ variable in the parent process.
	
	- execlp, execvp, execvpe 	(p): when looking for the executable, will do the same actions as the shell in looking for the file (use PATH environment variable, etc).
									 all others use their file input as relative or absolute file paths.

*/


int main() {
	int f = fork();

	if (f < 0) {
		printf("forking failed: %d", f);
	} else if (f == 0) {
		execl("/bin/ls", ".");
		execle("/bin/ls", ".");
		execlp("/bin/ls", ".");
		char* params[1] = { "." };
		execv("/bin/ls", params);
		execvp("/bin/ls", params);
		//execvpe("/bin/ls", "."); // for some reason cannot use. probably due to __USE_GNU
	} else {
		wait(NULL);
	}

}
