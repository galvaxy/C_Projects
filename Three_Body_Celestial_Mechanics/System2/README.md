INTIAL VALUES FOR THIS SYSTEM:

 This system simulates a binary star system with an orbiting planet. With the initial parameters given below it is found that the planet is in a ejected out of the system. The initial conditions for the binary stars are the same as System1 but the intial conditions for the planet are changed.  

 Masses (Ms = Mass of Sun, Me =  Mass of Earth - in kg):

  Mstar1 -> 5 Ms
  Mstar2 -> Ms
  Mplanet -> 2 Me 

 Initial positions (all positions are in AU):
 
  The initial position of Star1 is calculated from the intial positions of Star2 and Planet such that the center of mass of the system is centered at the origin. Format is <X, Y, Z>

  Star2 position -> <1.5, 0, 0>
  Planet position -> <7.0, 0, 0>

 Initial velocities (all velocities are in AU/day):

  The initial velocity of Star2 is calculated from the the initial velocities of Star1 and Planet such that the center of momentum of the system is centered at the origin. Format is <Vx, Vy, Vz>

  Star1 velocity -> <0, 0.0090, 0.0020>
  Planet velocity -> <0, -0.005, 0.>

PLOTS:

 The plots.gp file is a GnuPlot script that can be run using GnuPlot in terminal to create plots and animations. A .jpeg file of the binary star system and planet orbits are shown in Orbits.jpeg. An animation of these orbits is shown in Orbits.gif. The radius of each body with respect to the center of mass is plotted in the Radii.jpeg file.