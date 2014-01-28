#ifndef CONTEXTE_H
#define CONTEXTE_H
#include <string>
#include <stdint.h>


class Contexte
{
    uint64_t _N;            // nombre de mots
    uint64_t _T;            // Notre T
    int _mot_taille_min;  // nombre de lettres min d'un mot
    int _mot_taille_max;  // nombre de lettres max d'un mot
    uint64_t _N_taille[];   // tableau, nombre de mots d'une taille donnée
    int _nb_lettres;      // nombre de lettres possibles pour un caractère
    char _lettres[];      // tableau des lettres de taille _nb_lettres

    public:
        Contexte();
        virtual ~Contexte();

    // fonction de hachage
    // In: Clair c ----> Out: Empreinte. String is the return of the md5 function
    void h( std::string c, std::string & d );
    // In: position t, empreinte d ---> Retourne index.  String is the return of the md5 function
    uint64_t h2i( uint64_t t, std::string & d );
    // In: index idx ----> Out: Clair c.
    void i2c( uint64_t idx, std::string & c );
    // In: index idx ----> retourne index (la composée des précédentes)
    uint64_t i2i( uint64_t idx );
    // Retourne un indice aléatoire valide.
    uint64_t randIndex();

};

#endif // CONTEXTE_H
