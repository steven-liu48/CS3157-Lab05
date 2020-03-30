  - Steven Liu
  - xl2948
  - lab 4

1a)
Works as required by the lab handout.

1b) 
The process tree is below:
 3323 11968 11968 11968 ?           -1 Ss       0   0:00  \_ sshd: xl2948 [priv]
11968 12117 11968 11968 ?           -1 S     3951   0:00  |   \_ sshd: xl2948@pts/19
12117 12148 12148 12148 pts/19    4655 Ss    3951   0:00  |       \_ -bash
12148  4655  4655 12148 pts/19    4655 S+    3951   0:00  |           \_ ./a.out 11111
 4655  4656  4655 12148 pts/19    4655 S+    3951   0:00  |               \_ /bin/sh ./mdb-lookup-server-nc.sh 11111
 4656  4658  4655 12148 pts/19    4655 S+    3951   0:00  |                   \_ cat mypipe-4656
 4656  4659  4655 12148 pts/19    4655 S+    3951   0:00  |                   \_ nc -l 11111
 4656  4660  4655 12148 pts/19    4655 S+    3951   0:00  |                   \_ /bin/sh /home/jae/cs3157-pub/bin/mdb-lookup-cs3157
 4660  4661  4655 12148 pts/19    4655 S+    3951   0:00  |                       \_ /home/jae/cs3157-pub/bin/mdb-lookup /home/jae/cs3157-pub/bin/mdb-cs3157
Shell scripts:
mdb-lookup-server-nc.sh

1c)
Run "make vtest" to use valgrind.
The terminal output is below, which is the same as Jae's except for the process ID:
port number: 8888
[pid=8003] mdb-lookup-server started on port 8888

port number: 9999
[pid=8072] mdb-lookup-server started on port 9999

port number: 7777
[pid=8118] mdb-lookup-server started on port 7777

port number: 
[pid=8072] mdb-lookup-server terminated
port number: 
port number: 
port number: 
port number: 
[pid=8003] mdb-lookup-server terminated
[pid=8118] mdb-lookup-server terminated
port number: 
port number: 
port number: ^C
