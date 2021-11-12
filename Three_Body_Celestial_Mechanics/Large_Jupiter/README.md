INITIAL VALUES FOR THE SYSTEM:

 This system is the same as the solar system excpet the mass of Jupiter is multiplied by 1000 given the gas giant roughly the same mass as the Sun. The Earth is still 1 Au from the Sun initially and its velocity is unchanged. Jupiter is still 5.2 AU from the Sun initially and its velocity is now split between the planet and the Sun in such a way that the relative velocity between the Sun and Jupiter remains unchanged. It can be seen in the animation that the Earth will continue to orbit the Sun for some time before it gets passed to Jupiter. Finally the Earth is ejected from the solar system. The time step for this system is dt = 1 day.
 
Masses (Ms = Mass of Sun, Me =  Mass of Earth, Mj = Mass of Jupiter - in kg):

  M1 -> Ms
  M2 -> 1000*Mj
  Mplanet -> Me 

 Initial positions (all positions are in AU):
 
  The initial position of body3 is calculated from the intial positions of body1 and body3 such that the center of mass of the system is centered at the origin. Format is <X, Y, Z>

  body1 position -> <5.2 / (1 + m1 / m2), 0, 0>
  body3 position -> <5.2 / (1 + m1 / m2) + 1, 0, 0>

 Initial velocities (all velocities are in AU/day):

  The initial velocity of body1 is calculated from the the initial velocities of body2 and body3 such that the center of momentum of the system is centered at the origin. Vj = velocity of Jupiter and Ve = velocity of the Earth. Format is <Vx, Vy, Vz>

  body2 velocity -> <0,- vj / (1 + m2 / m1), 0>
  body3 velocity -> <0, ve, 0.>

PLOTS:

 The plots.gp file is a GnuPlot script that can be run using GnuPlot in terminal to create plots and animations. A .jpeg file of the binary star system and planet orbits are shown in Orbits.jpeg. An animation of these orbits is shown in Orbits.gif. The radius of each body with respect to the center of mass is plotted in the Radii.jpeg file.

 