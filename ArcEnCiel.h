#ifndef ARCENCIEL_H
#define ARCENCIEL_H

#include <stdint.h>
#include <string>
#include "Contexte.h"

struct Chaine {
  uint64_t idx1;    // premier indice de la chaine
  uint64_t idxT;    // dernier indice de la chaine
};

class ArcEnCiel {
  int _numero;   // numero de la table (ici 0, mais voir "Moult tables")
  int _M;        // nombre de chaines dans la table
  int _T;        // taille de chaque chaine
  Chaine* _X;    // la table elle-meme

  public:
  ArcEnCiel(Contexte c, int M, int T);
  ~ArcEnCiel();
  // Creer les M chaînes de taille T, dans le contexte ctxt
  void creer(Contexte &c, int num);
  // Tri _X suivant idxT.
  void trier();
  // Sauvegarde la table sur disque.
  void save( std::string name );
  // Charge en mémoire la table à partir du disque.
  void load( std::string name );
  // Recherche dichotomique dans la table
  // ( p et q sont le premier/dernier trouvé )
  bool recherche( uint64_t idx, uint64_t & p, uint64_t & q );
  // getter for _X
  Chaine getX(uint64_t idx) const;

};

#endif // ARCENCIEL_H
