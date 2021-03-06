#include "ArcEnCiel.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

const string separateur = "->";

ArcEnCiel::ArcEnCiel()
{

}

ArcEnCiel::~ArcEnCiel()
{
    delete []_X;
}


// Creer les M chaînes de taille T, dans le contexte ctxt
void ArcEnCiel::creer(Contexte &c, int M, int T)
{
    _M = M;
    _X = new Chaine[_M];
    _T = T;
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
            idx = c.i2i(j, idx);
        }

        // stock indc finale
        _X[i].idxT = idx;
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
   // for (n=0; n<_M; n++)
  //      cout << _X[n].idx1 << "-" << _X[n].idxT << endl;
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
            ifin = im;  // on recommence sur partie inferieure
        else
            id = im;  // pareil sur partie superieure
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

Chaine* ArcEnCiel::getX() const
{
    return _X;
}

int ArcEnCiel::getT() const
{
    return _T;
}

void ArcEnCiel::save( std::string name )
{
    name += ".koin";
    // Si ça ne compile pas la, c'est qu'il faut rajouter -std=c++11 en option au compilateur
    std::ofstream fichier(name.c_str(), ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

    if(fichier)
    {
        fichier << _M << endl;
        fichier << _T << endl;

        for (int i = 0; i < _M; ++i )
        {
            fichier << _X[i].idx1 << separateur << _X[i].idxT << endl;
        }

        fichier.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(1);
    }
}

void ArcEnCiel::load( std::string name)
{
    stringstream stream1;
    name += ".koin";
    // Si ça ne compile pas la, c'eest qu'il faut rajouter -std=c++11 en option au compilateur
    std::ifstream fichier(name.c_str(), ios::in);  // on ouvre en lecture

    if(fichier)  // si l'ouverture a fonctionné
    {
        string contenu;  // déclaration d'une chaîne qui contiendra la ligne lue
        // recupere M
        getline(fichier, contenu);
        stream1.clear();
        stream1.str(contenu);

        stream1 >> _M;

        // recupere T
        getline(fichier, contenu);
        stream1.clear();
        stream1.str(contenu);
        stream1 >> _T;


        // init table des chaines
        _X = new Chaine[_M];

        for (int i = 0; i < _M; ++i )
        {
            // on recup la ligne
            getline(fichier, contenu);
            // on cherche la "->" qui sépare les indexs
            string::size_type loc = contenu.find( separateur, 0 );

            if( loc != string::npos )
            {
                stream1.clear();
                stream1.str(contenu.substr(0,loc));
                stream1 >>  _X[i].idx1;

                stream1.clear();
                stream1.str(contenu.substr(loc+separateur.length()));
                stream1 >>  _X[i].idxT;
                //cout << "Insérer correctement : ligne " << i+2 << loc << endl;
            }
            else
            {
                cout << "Fichier mal formaté, erreur ligne " << i+2 << endl;
            }
        }

        fichier.close();
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        exit(1);
    }
}


