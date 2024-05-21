//  In this file we'll define the class InitAutomata that will be used to initialize the automata

typedef struct State
{
    int id;
    int is_final;
    struct Transition *transitions;
    int num_transitions;
}State;


typedef struct Transition
{
    char symbol;
    State *destination;
};

typedef struct Automata
{
    State *states;
    int num_states;
    State *start_state;
}Automata;

// Here we define the initialisation Signature

Automata Initialise(int numstates, int numtransitions, int* finalstates, int startid);