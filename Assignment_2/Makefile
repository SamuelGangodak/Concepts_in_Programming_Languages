all : heap.o driver.o 
	gcc heap.o driver.o -o final.exe

heap.o : heap.c
	gcc -c heap.c

driver.o : driver.c
	gcc -c driver.c

clean : 
	del *.o *.exe