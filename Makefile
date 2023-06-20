make: clean main.o stack.o string.o queue.o hashset.o
	cc -o executable main.o stack.o string.o queue.o hashset.o
main.o:
	cc -c learn/main.c
stack.o:
	cc -c learn/data_structure/stack.c
queue.o:
	cc -c learn/data_structure/queue.c
hashset.o:
	cc -c learn/data_structure/hashset.c
string.o:
	cc -c learn/data_structure/string.c
clean:
	rm -rf executable main.o stack.o string.o queue.o hashset.o