harmonic_oscillator: main.o euler_calc.o runge_kutta_calc.o analytical_calc.o error_analysis.o write.o 
	gcc main.o euler_calc.o runge_kutta_calc.o analytical_calc.o error_analysis.o write.o -o harmonic_oscillator

main.o: main.c 
	gcc -c main.c 

euler_calc.o: euler_calc.c 
	gcc -c euler_calc.c 

runge_kutta_calc.o: runge_kutta_calc.c 
	gcc -c runge_kutta_calc.c 

analytical_calc.o: analytical_calc.c 
	gcc -c analytical_calc.c 

error_analysis.o: error_analysis.c 
	gcc -c error_analysis.c 

write.o: write.c 
	gcc -c write.c 

clean:
	rm *.o harmonic_oscillator