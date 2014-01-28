#include <iostream>
#include <math.h>
#include "Contexte.h"

#include <stdlib.h>
#include <time.h>

#include <openssl/md5.h>
#include <openssl/sha.h>

using namespace std;

Contexte::Contexte()
{
    //ctor
    //init randoms
    srand (time(NULL));
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

uint64_t Contexte::h2i( uint64_t t, std::string &d )
{
    //TODO use t
    uint64_t* ptr = (uint64_t*) d.c_str(); // le tableau de caractères est vu comme un tableau de grand nombre.
    uint64_t i = *ptr; // par définition le nombre stocké dans t[0-7].
    return i;
}


uint64_t Contexte::randIndex()
{
    unsigned long n1 = random();
    unsigned long n2 = random();
    uint64_t n = ( (uint64_t) n2 )+ ( ( (uint64_t) n1 ) << 32 );
    return n;
}



/*
void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
  MD5(pPlain, nPlainLen, pHash);
}
void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
  SHA1(pPlain, nPlainLen, pHash);
}
*/
