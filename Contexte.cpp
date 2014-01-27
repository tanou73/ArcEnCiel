#include <iostream>
#include <math.h>
#include "Contexte.h"

using namespace std;

Contexte::Contexte()
{
    //ctor

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

    // generer un nb aleatoire (seeder)

    // Choisir un T
    _T = _N/2;

    // Initialiser le tableau de correspondance


    // populer le tableau
        // on part de notre indice seeder
        // boucle pendant M
            // re-seed un nombre indc
            // stock indc
            //boucle sur T
                // c <- i2c(indc)
                // h <- h(c)
                // indc <- h2i(h)
            // end loop
            // stock indc finale
        //end loop

}

Contexte::~Contexte()
{
    //dtor
}

