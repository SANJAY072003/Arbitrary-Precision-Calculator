obj =$(patsubst %.c,%.o,$(wildcard *.c))
apc.exc : $(obj)
	gcc -o apc.exc $(obj)

clean:
	rm *.exe *.o