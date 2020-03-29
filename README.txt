  - Steven Liu
  - xl2948
  - lab 4

1a)

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

