celestial_mechanics: main.o initialize.o calculate.o 
	gcc main.o initialize.o calculate.o -o celestial_mechanics

main.o: main.c 
	gcc -c main.c 

initialize.o: initialize.c 	
	gcc -c initialize.c 	

calculate.o: calculate.c 
	gcc -c calculate.c 

clean: 
	rm *.o celestial_mechanics