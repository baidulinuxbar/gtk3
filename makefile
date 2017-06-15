g09:g09.c
	gcc -o g09 g09.c `pkg-config --cflags --libs gtk+-3.0` -I/workarea/cprogram/include/
clean:
	rm g09

