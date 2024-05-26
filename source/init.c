#include "../headers/init.h"
#include <stddef.h>
// Cette partie initialise les ensembles d'etat

Etat *createEtat(int id, bool estInit, bool estTerm)
{
    Etat *etat = (Etat *)malloc(sizeof(Etat));
    etat->id = id;
    etat->estInit = estInit;
    etat->estTerm = estTerm;
    etat->transitions = NULL;
    etat->numTransitions = 0;
    return etat;
}

void ajouteTransition(Etat *etat, char c, Etat *succ)
{
    if (etat->numTransitions == 0)
    {
        etat->transitions = (EnsEtat **)malloc(26 * sizeof(EnsEtat *));
        for (int i = 0; i < 26; i++)
        {
            etat->transitions[i] = createEnsEtat(2);
        }
    }
    addEtatToEns(etat->transitions[c - 'a'], succ);
}

EnsEtat *createEnsEtat(int capacity)
{
    EnsEtat *ens = (EnsEtat *)malloc(sizeof(EnsEtat));
    ens->etats = (Etat **)malloc(capacity * sizeof(Etat *));
    ens->size = 0;
    ens->capacity = capacity;
    return ens;
}

void addEtatToEns(EnsEtat *ens, Etat *etat)
{
    if (ens->size >= ens->capacity)
    {
        ens->capacity *= 2;
        ens->etats = (Etat **)realloc(ens->etats, ens->capacity * sizeof(Etat *));
    }
    ens->etats[ens->size++] = etat;
}

bool containsEtat(EnsEtat *ens, int id)
{
    for (int i = 0; i < ens->size; i++)
    {
        if (ens->etats[i]->id == id)
            return true;
    }
    return false;
}

Automate *createAutomate(int capacity)
{
    Automate *automate = (Automate *)malloc(sizeof(Automate));
    automate->etats = createEnsEtat(capacity);
    automate->initiaux = createEnsEtat(capacity);
    return automate;
}

bool ajouteEtatSeul(Automate *automate, Etat *etat)
{
    if (containsEtat(automate->etats, etat->id))
        return false;
    addEtatToEns(automate->etats, etat);
    if (etat->estInit)
        addEtatToEns(automate->initiaux, etat);
    return true;
}

bool ajouteEtatRecursif(Automate *automate, Etat *etat)
{
    if (!ajouteEtatSeul(automate, etat))
        return false;
    for (int i = 0; i < etat->numTransitions; i++)
    {
        EnsEtat *ens = etat->transitions[i];
        for (int j = 0; j < ens->size; j++)
        {
            ajouteEtatRecursif(automate, ens->etats[j]);
        }
    }
    return true;
}

bool estDeterministe(Automate *automate)
{
    for (int i = 0; i < automate->etats->size; i++)
    {
        Etat *etat = automate->etats->etats[i];
        for (int j = 0; j < etat->numTransitions; j++)
        {
            EnsEtat *ens = etat->transitions[j];
            if (ens->size > 1)
                return false;
        }
    }
    return true;
}
// ---------------------------------- 1er approche ---------------------------------------------------------------

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
