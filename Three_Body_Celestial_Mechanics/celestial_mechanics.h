#ifndef CELESTIAL_MECHANICS_H
#define CELESTIAL_MECHANICS_H

#define G 1.488082603*pow(10,-34) //Gravitational constant, units-> AU^3/(kg*days^2)
#define dt 7 //Time step, units-> days
#define MAXj 1500 //Total number of time steps to be calculated
#define Ms 1.989*pow(10,30)//Mass of Sun in kg 
#define Me 5.972*pow(10,24) //Mass of Earth in kg

double x[3][MAXj],y[3][MAXj],z[3][MAXj]; //Arrays to hold positions of three bodies at the j'th time step (ex. x[1][j]=x position of body 1 at time j)
double vx[3][MAXj],vy[3][MAXj],vz[3][MAXj]; //Arrays to hold velocities of the three bodies at the j'th time step (ex. vx[1][j]=x component of velocity of body 1 at time j)
double RR[3]; //Array to hold the dot products between position vectors of the three bodies at j'th time step (RR[1][j]=R1*R2, RR[2][j]=R1*R3, RR[3][j]=R2*R3).
double RMag[3]; //Array to hold the magnitude of the position vectors of each body at j'th time step
double rMag[3]; // Array to hold the magnitude of the relative displacement vector of the three bodies at j'th time step (ex. rMag[1][j]=Distance between body 1 and body 2 at time j)
double m1,m2,m3; //These variables hold the value of the masses of the three bodies

/* ********************************************************** */
/* ********************** Initialize ************************ */
/* ********************************************************** */
void initialize();

 

/* ********************************************************** */
/* *********************** Calculate ************************ */
/* ********************************************************** */
void calculate();

#endif