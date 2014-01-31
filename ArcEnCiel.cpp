#include "ArcEnCiel.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>

using namespace std;

ArcEnCiel::ArcEnCiel(Contexte c, int M, int T)
{
    _M = M;
    _X = new Chaine[_M];
    _T = T;

    creer(c, 0);
}

ArcEnCiel::~ArcEnCiel()
{
    delete []_X;
}

// Creer les M chaînes de taille T, dans le contexte ctxt
void ArcEnCiel::creer(Contexte &c, int num)
{
    // populer le tableau
    // boucle pendant M
    for (int i = 0; i < _M; ++i)
    {
        // re-seed un nombre indc
        uint64_t idx = c.randIndex();
        // stock indc
        _X[i].idx1 = idx;

        //boucle sur T
        for(int j = 0; j < _T; ++j)
        {
            idx = c.i2i(idx);
        }

        // stock indc finale
        _X[i].idxT = idx;

        cout << "chaine" << i << " : " << _X[i].idx1 << "-" << _X[i].idxT << endl;
    }
}


bool compare (Chaine const &a, Chaine const &b)
{
    return ( a.idxT < b.idxT );
}

void ArcEnCiel::trier()
{
    int n;
    std::sort(_X, _X + _M, compare);
    for (n=0; n<_M; n++)
        cout << _X[n].idx1 << "-" << _X[n].idxT << endl;
}

bool ArcEnCiel::recherche( uint64_t idx, uint64_t & p, uint64_t & q )
{
    /* déclaration des variables locales à la fonction */
    bool trouve = false;  //vaut faux tant que la valeur "val" n'aura pas été trouvée
    uint64_t id = 0;  //indice de début
    uint64_t ifin = _M-1;  //indice de fin
    uint64_t im;  //indice de "milieu"

    /* boucle de recherche */
    while(!trouve && ((ifin - id) > 1))
    {
        im = (id + ifin)/2;  // milieu du tableau

        trouve = ( _X[im].idxT == idx);  // on regarde si c'est la valeur

        if( _X[im].idxT > idx )
            ifin = im;  // on recommence sur partie supérieur
        else
            id = im;  // pareil sur partie inférieur
    }

    if( _X[id].idxT == idx )
    {
        p = _X[id].idx1;
        q = _X[id].idxT;
        return true;
    }
    else
        return false;
}

Chaine ArcEnCiel::getX(uint64_t idx) const
{
    return _X[idx];
}
/*
void ArcEnCiel::save( std::string name )
{
    ofstream fichier(name+".koin", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

    if(fichier)
    {
        fichier << _M << endl;
        for (int i = 0; i < _M; ++i )
        {
            fichier << _X[i].idx1 << "::" << _X[i].idxT << endl;
        }

        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

void ArcEnCiel::load( std::string name, int T )
{
    ifstream fichier(name+".koin", ios::in);  // on ouvre en lecture

    if(fichier)  // si l'ouverture a fonctionné
    {
        string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
        getline(fichier, contenu);  // on met dans "contenu" la ligne
        _M = std::stoi( contenu );
        _X = new Chaine[_M];


        cout << contenu;  // on affiche la ligne

        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

    return 0;
}

*/


