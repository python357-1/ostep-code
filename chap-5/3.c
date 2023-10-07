#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {

	int f = fork();

	if (f < 0) {
		printf("error: %d", f);
	} else if (f == 0) {
		//child
		printf("hello");
	} else {
		//parent
		sleep(1);
		printf("goodbye");
	}
}
