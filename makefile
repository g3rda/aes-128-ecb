all:
	gcc -static main.c aes.c aes.h -o aes

clean:
	rm -rf aes
