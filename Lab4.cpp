#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define READ 0

#define WRITE 1




char* output1 = "from parent to child";

char* output2 = "from child to parent";

int main() {

	int fd[2][2], bytesRead[2];

	char message[2][100];

	pipe(fd[0]); //use of pipe function

	pipe(fd[1]);

	if (fork() == 0) {//child fork returns zero



		close(fd[0][READ]); //use of close read

		close(fd[1][WRITE]); //use of close write



		write(fd[0][WRITE], output1, strlen(output1) + 1);

		close(fd[0][WRITE]);





		bytesRead[1] = read(fd[1][READ], message[1], 100); //storing into bytesRead

		printf("Read %d bytes: %s\n", bytesRead[1], message[1]);
		printf("ID=%d\n", getpid());
		printf("Parent ID=%d\n", getppid());
		close(fd[0][READ]);

	}

	else {//returns PID of child

		close(fd[0][WRITE]);

		close(fd[1][READ]);



		bytesRead[0] = read(fd[0][READ], message[0], 100); //storing into bytesRead

		printf("Read %d bytes: %s\n", bytesRead[0], message[0]);
		printf("ID=%d\n", getpid());

		close(fd[0][READ]);





		write(fd[1][WRITE], output2, strlen(output2) + 1);

		close(fd[1][WRITE]);

	}

}