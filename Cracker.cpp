#include <iostream>
#include <string>

#include "Cracker.h"
#include "ArcEnCiel.h"
#include "Contexte.h"

using namespace std;
/*
bool Cracker::cracker( std::string& y, ArcEnCiel& aec, Contexte& ctxt, std::string& clair )
{
     int T = aec.getT();

     int nb_fausses_alertes = 0;
     for ( int t = T - 1; t > 0; --t ) {
        // fabrication du bon indice
        uint64_t idx = ctxt.h2i( t, y );
        for ( uint64_t k = t + 1; k <= T - 1; ++k ) {
          idx = ctxt.i2i( k, idx );
        }
        // Recherche dans la table.
        uint64_t p;
        uint64_t q;
        if ( aec.recherche( idx, p, q ) ) {
          // On vérifie chacune des alertes
          for ( uint64_t m = p; m <= q; ++m ) {
            if ( verifieAlerte( y, aec.getX(), t, m, clair ) )
              return true;
            nb_fausses_alertes++;
          }
        }
     }
     cout << "Non trouve, fausses alertes = " << nb_fausses_alertes;
     return false;

}

bool Cracker::verifieAlerte( std::string & y, Chaine* X, int t, uint64_t & m,  std::string& clair )
{

}*/

/*bool Cracker::cracker( std::string& y, ArcEnCiel& aec, Contexte& c, std::string& clair )
{
    uint64_t idx = c.h2i(0, y);

    uint64_t p;
    uint64_t q;

    // Boucle sur le nombre de colonnes (T)
    for ( uint64_t i = 0; i < aec.getT(); ++i ) {

        cout << "lol1" << endl;
        if ( aec.recherche( idx, p, q ) )
        {
            cout << "yolo lol " << endl;
            uint64_t idx_tmp = p;
            for (uint64_t k = 0; k < aec.getT(); ++k)
            {
                c.i2c(idx_tmp, clair);
                cout << "looping : " << clair << endl;
                string hash_tmp;
                c.h(clair, hash_tmp);
                if (hash_tmp == y)
                    return true;
                else
                {
                    idx_tmp = c.h2i(k, hash_tmp);
                    clair = "";
                }
            }
        }
        else
        {
            idx = c.i2i( i, idx );
            cout << "lol2" << idx << endl;
        }

    }


}*/

bool Cracker::cracker( std::string& y, ArcEnCiel& aec, Contexte& c, std::string& clair )
{
    uint64_t i;
    // On essai avec plusieurs départ (on part en colonne T, puis T-1 puis T-2 ..etc
    for (uint64_t t = aec.getT() -1; t >= 0; --t)
    {
        // On recupere le hash correspondant à la colonne choisi par la boucle (le hash de T-3 sera t = 2 pour T = 5 colonne par exemple)
        i = c.h2i(t, y);

        // on suit ensuite le bon nombre fois l'arc en ciel jusqu'au bout pr arriver au dernier indice (t=T-1)
        for (uint64_t k = t +1; k < aec.getT(); ++k)
        {
            i = c.i2i(k, i);
        }

        // on effectu la recherche dichotomique sur l'indice trouvé precedemment
        uint64_t p, q;
        uint64_t id;
        if ( aec.recherche( i, p, q ) )
        {
            // on init notre id avec la valeur p (premier indice)
            id = p;

            // on parcours de p à q
            for(uint64_t w = 0; w < aec.getT(); ++w)
            {
                // on recupere le clair et on le hash
                c.i2c(id, clair);
                string hash;
                c.h(clair, hash);
                // on verifie que notre hash est bien egale au texte que l'on veut déchiffrer sinon on continu notre arc
                if (hash == y)
                    return true;
                else
                    id = c.h2i(w, hash);
            }
        }
    }
}
