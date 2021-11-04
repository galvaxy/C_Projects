newton_raphson: main.o initialize.o calculate.o display.o write.o
	gcc main.o initialize.o calculate.o display.o write.o -o newton_raphson 

main.o: main.c
	gcc -c main.c

initialize.o: initialize.c
	gcc -c initialize.c

calculate.o: calculate.c
	gcc -c calculate.c

display.o: display.c
	gcc -c display.c

write.o: write.c
	gcc -c write.c

clean:
	rm *.o newton_raphson