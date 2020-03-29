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

	printf("port number: ");
	char input[1000];
	while(1){
		fgets(input, 1000, stdin);
		char *port = calloc(6, 1);
        strncpy(port, input, 5);
        for(int i=0; i<6; i++){
            if(!isprint(port[i])){
                port[i] = '\0';
            }
        }
		if (port[0] == '\n'){
			printf("port number: ");
			continue;
		}
    	pid_t pid = fork();
 		if (pid < 0) {
			die("fork failed");
    	} else if (pid == 0) {
	    	// child process
    		fprintf(stderr, "[pid=%d] ", (int)getpid());
    		fprintf(stderr, "mdb-lookup-server started on port %s\n", port);
    		execl("./mdb-lookup-server-nc.sh", "mdb-lookup-server-nc.sh", port, (char *)0);
	    	die("execl failed");
    	} else {
    		// parent process
    		if (waitpid(pid,
            	NULL, // no status
            	0) // no options
        	!= pid)
        	die("waitpid failed");
    		fprintf(stderr, "[pid=%d] ", (int)pid);
    		fprintf(stderr, "mdb-lookup-server terminated\n");
			printf("port number: ");
    	}
		free(port);
		fflush(stdin);
		//printf("\nport number: ");
	}
    return 0;
}
