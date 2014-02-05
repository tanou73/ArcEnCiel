#include <iostream>
#include <string>

#include "Cracker.h"
#include "ArcEnCiel.h"
#include "Contexte.h"

using namespace std;

bool Cracker::cracker( std::string& y, ArcEnCiel& aec, Contexte& ctxt, std::string& clair )
{
     int T = aec.getT();



     int nb_fausses_alertes = 0;
     for ( int t = T - 1; t > 0; --t ) {
        // fabrication du bon indice
   /*     uint64_t idx = ctxt.h2i( t, y );
        for ( uint64_t k = t + 1; k <= T - 1; ++k ) {
          idx = ctxt.i2i( k, idx );
        }
        // Recherche dans la table.
        if ( aec.recherche( idx, p, q ) ) {
          // On vérifie chacune des alertes
          for ( uint64_t m = p; m <= q; ++m ) {
            if ( VerifieAlerte( y, aec._X, t, m, clair ) )
              return true;
            nb_fausses_alertes++;
          }
        }*/
     }
     cout << "Non trouve, fausses alertes = " << nb_fausses_alertes;
     return false;
}
