
// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include "creature.h"
#include "neuron.h"
#include "grid.h"
#include "config.h"
#include "globals.h"
#include "errors.c"
#include "genome.h"
//#include "neuron_calculations.c"



// Notes
// Mutation 1:1000 per genome
// https://youtu.be/N3tRFayqVtk?si=DoGmfUdZsobps68d
// fire mechanic and night
// premade file with scenario (gen 1000 wall)



// Main function
int main() {
    // Error hendeling
    if (checkForErrors()) return 1;

    // Random seed based on time
    srand(time(NULL));

    currentGenStep = 0;
    Grid* grid = Grid_create();
    initializeNeurons(grid);
    Genome brain_alive[CREATURES_IN_GEN][BRAIN_SIZE];
    unsigned int creaturesAlive;
    int generationNum = 0;


    // Creating list of creatures
    int (*validGridCoords)[2];
    Creature* genOfCreatures[CREATURES_IN_GEN];


    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < CREATURES_IN_GEN; j++) {
            validGridCoords = findEmptySpaceGrid(grid);
            setGrid(grid, (*validGridCoords)[0], (*validGridCoords)[1], 10000+j);
            if (generationNum == 0) {
                genOfCreatures[j] = Creature_create(j, (*validGridCoords)[0], (*validGridCoords)[1], NULL); // might make it more optimal in future, dont like two same lines
            } else {
                genOfCreatures[j] = Creature_create(j, (*validGridCoords)[0], (*validGridCoords)[1], brain_alive[rand()%creaturesAlive]);
            }
        }

        printf("Gen %d:\n", i);
        for (int j = 0; j < CREATURES_IN_GEN; j++) {
            printBrainCreature(genOfCreatures[j]);
            printf("\n");
        }
        for (currentGenStep = 0; currentGenStep < GENERATION_STEPS; currentGenStep++) {
            for (int c = 0; c < CREATURES_IN_GEN; c++) {
                creatureStep(genOfCreatures[c]);
            }
        }
        creaturesAlive = 0;
        for (int c = 0; c < CREATURES_IN_GEN; c++) {
            if (genOfCreatures[c]->gridPosX >= ALIVE_START_X &&
                genOfCreatures[c]->gridPosX <= ALIVE_END_X &&
                genOfCreatures[c]->gridPosY >= ALIVE_START_Y &&
                genOfCreatures[c]->gridPosY <= ALIVE_END_Y) {
                    creaturesAlive++;
                    memcpy(brain_alive[creaturesAlive-1], genOfCreatures[c]->brain, sizeof(genOfCreatures[c]->brain));
            }
        }/*
        printf("Copied brains: \n");
        for (int tt = 0; tt < creaturesAlive; tt++) {
            for (int uu = 0; uu < BRAIN_SIZE; uu++) {
                printf("%x\n", brain_alive[tt][uu]);
            }
            printf("\n");
        }
        */
        printf("%d\n", creaturesAlive);
        generationNum++;
        // Destroying creatures
        for (int c = 0; c < CREATURES_IN_GEN; c++) {
            Creature_destroy(genOfCreatures[c]);
        }
        //printGrid(grid);
        clearGrid(grid);

        printf("\n");
    }
    destroyNeurons();
    Grid_destroy(grid);
    
    return 0;
}
