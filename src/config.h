
#ifndef CONFIG_H
#define CONFIG_H

#define BRAIN_SIZE 6
#define CREATURES_IN_GEN 100
#define GENERATION_STEPS 300

// Grid specifications
#define GRID_X 30
#define GRID_Y 30
#define NEURON_LIST_SIZE 64
#define MAX_INNER_NEURON_COUNT 100 // better to not change, naming will go brrr
#define MUTATION_RATE 40 // Gives the chance of mutation 1 / n

#define SENSORY_NEURONS 6
#define INNER_NEURONS 3
#define ACTION_NEURONS 5

#define ALIVE_START_X 0
#define ALIVE_START_Y 0

#define ALIVE_END_X 15
#define ALIVE_END_Y 15


#endif // CONFIG_H
