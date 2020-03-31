/*
 * mdb-lookup-server-nc-2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

static void die(const char *s)
{
    perror(s);
    exit(1);
}


int main(int argc, char **argv)
{
	//Check terminal input
    if (argc != 1) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
    	exit(1);
    }
	
	//Print and initialize variables
	printf("port number: ");
	char port[100];
	pid_t pid = 0;

	//Use 1 as the loop parameter, and quit when user inputs Ctrl + C
	while(1){
		//Check child processes status
		while ((pid = waitpid( (pid_t) -1, NULL, WNOHANG)) > 0){
            fprintf(stderr, "[pid=%d] ", (int)pid);
            fprintf(stderr, "mdb-lookup-server terminated\n");
        }
		//Read user input
		//printf("port number: ");
		fgets(port, sizeof(port), stdin);
		if (port[strlen(port)-1] == '\n'){
			port[strlen(port)-1] = 0;
		}
		//If user presses ENTER...
		if (port[0] == 0){
			printf("port number: ");
			continue;
		}

		//Just fork
    	pid = fork();
 		if (pid < 0) {
			die("fork failed");
    	} else if (pid == 0) {
	    	//child process: execl
    		fprintf(stderr, "[pid=%d] ", (int)getpid());
    		fprintf(stderr, "mdb-lookup-server started on port %s\n", port);
    		execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh", port, (char *)0);
	    	die("execl failed");
    	} else {
    		//parent process: continue the loop
			printf("port number: ");
    	}
		fflush(stdin);
	}
    return 0;
}
