wave_superposition: main.o initialize.o calculate.o 
	gcc main.o initialize.o calculate.o -o wave_superposition

main.o: main.c 
	gcc -c main.c 

initialize.o: initialize.c 
	gcc -c initialize.c 

calculate.o: calculate.c 
	gcc -c calculate.c 

clean:
	rm *.o wave_superposition