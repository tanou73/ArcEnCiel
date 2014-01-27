#include <iostream>
#include <math.h>
#include "Contexte.h"

using namespace std;

Contexte::Contexte()
{
    //ctor
    /*
        uint64_t _N;            // nombre de mots
    int _mot_taille_min;  // nombre de lettres min d'un mot
    int _mot_taille_max;  // nombre de lettres max d'un mot
    uint64_t _N_taille[];   // tableau, nombre de mots d'une taille donnée
    int _nb_lettres;      // nombre de lettres possibles pour un caractère
    char _lettres[];
    */

    // notre alphabet
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    _mot_taille_min = 3;
    _mot_taille_max = 3;

    // taille de notre alphabet
    _nb_lettres = alphabet.size();

    //TODO : faire une boucle qui calcule quand min != de max. On additione pr chaque taille
    _N = pow(_nb_lettres, _mot_taille_max);

    for (int i=0; i < _nb_lettres; i++){
        _lettres[i] = alphabet[i];
    }

    cout << "N = " << _N << " et nb lettre " << _nb_lettres << endl;
}

Contexte::~Contexte()
{
    //dtor
}

