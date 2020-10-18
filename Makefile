make: main.o stack.o
	cc -o executable main.o stack.o
main.o:
	cc -c learn/main.c
stack.o:
	cc -c learn/data_structure/stack.c
clean:
	rm -rf executable main.o stack.o