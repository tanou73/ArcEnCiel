#include "ArcEnCiel.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

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
        cout << _X[n].idxT << "-" << _X[n].idx1 << endl;
}





