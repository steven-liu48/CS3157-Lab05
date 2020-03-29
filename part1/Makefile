mdb-lookup-server-nc: mdb-lookup-server-nc-2.o
	gcc -g -Wall mdb-lookup-server-nc-2.o -o mdb-lookup-server-nc

mdb-lookup-server-nc-2.o: mdb-lookup-server-nc-2.c
	gcc -c -g -Wall mdb-lookup-server-nc-2.c

.PHONY: vtest
vtest: mdb-lookup-server-nc
	valgrind --leak-check=yes ./mdb-lookup-server-nc

.PHONY: clean
clean:
	rm -f *.o *.a mdb-lookup-server-nc
