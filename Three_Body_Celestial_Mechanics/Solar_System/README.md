INITIAL VALUES FOR THE SYSTEM:

 This system simulates the solar system. This system is meant to test the program for errors. Since the solar system behavior is already known it acts as a good check for the accuracy of the program. It can be seen in the animation that the Earth and Jupiter have very regular circular orbits and the sun is roughly at the center of mass of the system as expected. The time step for this system is dt = 1 day. 
 
Masses (Ms = Mass of Sun, Me =  Mass of Earth, Mj = Mass of Jupiter - in kg):

  M1 -> Ms
  M2 -> Mj
  Mplanet -> Me 

 Initial positions (all positions are in AU):
 
  The initial position of body1 is calculated from the intial positions of body2 and body3 such that the center of mass of the system is centered at the origin. Format is <X, Y, Z>

  body2 position -> <5.2, 0, 0>
  body3 position -> <-1, 0, 0>

 Initial velocities (all velocities are in AU/day):

  The initial velocity of body1 is calculated from the the initial velocities of body2 and body3 such that the center of momentum of the system is centered at the origin. Vj = velocity of Jupiter and Ve = velocity of the Earth. Format is <Vx, Vy, Vz>

  body2 velocity -> <0,vj, 0>
  body3 velocity -> <0, -ve, 0.>

PLOTS:

 The plots.gp file is a GnuPlot script that can be run using GnuPlot in terminal to create plots and animations. A .jpeg file of the binary star system and planet orbits are shown in Orbits.jpeg. An animation of these orbits is shown in Orbits.gif. The radius of each body with respect to the center of mass is plotted in the Radii.jpeg file.
