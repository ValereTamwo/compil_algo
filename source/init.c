#include "../headers/init.h"
#include <stddef.h>

Automata Initialise(int numstates, int numtransitions, int* finalstates, int startid){

    // Creation des etats
    Automata automata;
    automata.num_states = numstates;
    automata.states = (State*)malloc(numstates*sizeof(State));

    // Definition de l'etat Initial
    automata.start_state = &automata.states[startid];


    // Initialisation des etats
    for (int i = 0; i<numstates; i++){
        automata.states[i].id= i;
        automata.states[i].is_final = 0;
        automata.states[i].num_transitions = 0;
        automata.states[i].transitions =  NULL;
    }

    // Ajout des transitions
}
