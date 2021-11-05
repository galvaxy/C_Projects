integration: main.o newton_cotes.o simpson.o trapezoid.o save.o
	gcc main.o newton_cotes.o simpson.o trapezoid.o save.o -o integration

main.o: main.c 
	gcc -c main.c 

newton_cotes.o: newton_cotes.c 
	gcc -c newton_cotes.c 

simpson.o: simpson.c 
	gcc -c simpson.c 

trapezoid.o: trapezoid.c 
	gcc -c trapezoid.c 

save.o: save.c 
	gcc -c save.c 

clean:
	rm *.o integration
