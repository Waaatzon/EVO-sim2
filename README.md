# EVO-sim2
Evolution simulation based on [video](https://youtu.be/N3tRFayqVtk?si=YQMtKYalPkSQOpWn) from David Miller.

## Why?
I found an interest in video mentioned above, because the math and use of NN fascinated me. 
I tried to recreate the simulation in python from scratch, but the performance was not very good. 
The [repository](https://github.com/JanSchor/Evolution) of simulation in python is visible on my github.

Since I moved to uni and started learning C, I needed some project, that can gain me some experience.
This was perfect opportunity to improve the old project and make it in C.

## Current state
The project is not finished yet.

Right now major part of simulation works.
The program does not have visualization in command line anymore, but in separate python app.
Export of brains and generation recordings works now.
Simulation now can be ran with prewritten scenario inside file.

* Simulation ✅
* Generation export ✅
* Generation visualization ✅
* Brains export ✅
* Brains visualization ❌
* Generation brains import ✅
* Dynamic running values ✅
* Scenario import ✅
* Scenario creator ❌
* Additional functions and scenarios ❌
* Graphs ✅

There is folder named `export_formats` which has example files for how should the export or import look.
It also has specific README file for how should the scenario file look.

The scenario file is now required for running the simulation.