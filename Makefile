run:
	clear
	gcc -Wall MenuV3.c
	./a.out
debug_memory:
	clear
	gcc -Wall MenuV3.c
	clear
	valgrind --leak-check=full --show-leak-kinds=all -s ./a.out
clean:
	clear
	rm a.out
	rm -r export/*
	clear
