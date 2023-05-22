make: clean main.o stack.o string.o
	cc -o executable main.o stack.o string.o
main.o:
	cc -c learn/main.c
stack.o:
	cc -c learn/data_structure/stack.c
string.o:
	cc -c learn/data_structure/string.c
clean:
	rm -rf executable main.o stack.o string.o