#ifndef CONTEXTE_H
#define CONTEXTE_H


class Contexte
{
    uint64 _N;            // nombre de mots
    int _mot_taille_min;  // nombre de lettres min d'un mot
    int _mot_taille_max;  // nombre de lettres max d'un mot
    uint64 _N_taille[];   // tableau, nombre de mots d'une taille donnée
    int _nb_lettres;      // nombre de lettres possibles pour un caractère
    char _lettres[];      // tableau des lettres de taille _nb_lettres

    public:
        Contexte();
        virtual ~Contexte();

    // fonction de hachage
    // In: Clair c ----> Out: Empreinte
    void h( String c, Condense & d );
    // In: position t, empreinte d ---> Retourne index
    uint64 h2i( uint64 t, Condense & d );
    // In: index idx ----> Out: Clair c
    void i2c( uint64 idx, String & c );
    // In: index idx ----> retourne index (la composée des précédentes)
    uint64 i2i( uint64 idx );
    // Retourne un indice aléatoire valide.
    uint64 randIndex();
};

#endif // CONTEXTE_H
