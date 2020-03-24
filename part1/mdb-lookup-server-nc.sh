#!/bin/sh
on_ctrl_c() {
echo "Ignoring Ctrl-C"
}
pid=$$
mkfifo mypipe-"$pid"
cat mypipe-"$pid" | nc -l $1 | /home/jae/cs3157-pub/bin/mdb-lookup-cs3157 > mypipe-"$pid"
rm mypipe-"$pid"
