CELESTIAL MECHANICS -> THREE BODY PROBLEM:

 This program calculates the orbits, in 3-D, of three celestial bodies orbiting their center of mass. The program is working in the center of mass frame (Rcm=(0,0,0), Vcm=<0,0,0>). The program uses the Euler-Cromer algorithm to perform the calculations.

 Parameters for the system are initialized in initialize.c. All three masses are independent of each other (Units-> kilograms).
 Since the center of mass must be at (0,0,0) only two of the position vectors are independent. The two independent bodies are chosen to be bodies 2 and 3. The initial position of body 1 is then dependent on the initial positions of bodies 2 and 3 (Units-> AU). Since the velocity of the center of mass must be <0,0,0,> only two velocities are independent. The two independent bodies are 1 and 3; therefore they have the independent velocities and the velocity of body 2 is dependent (Units-> AU per day).

 The orbits of the three bodies are calculated and saved to .txt files in calcuate.c. For a given set of parameters a new directory is made to hold all resulting .txt files. The name of the directory and .txt files can be changed in calculate.c.