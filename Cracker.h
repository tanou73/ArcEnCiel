#ifndef CRACKER_H
#define CRACKER_H

#include <iostream>
#include <string>
#include "ArcEnCiel.h"

class Cracker
{
    public:

    bool cracker(std::string& y, ArcEnCiel& aec, Contexte& ctxt, std::string& clair );

    bool verifieAlerte( std::string & y, Chaine* X, int t, uint64_t & m,  std::string& clair );
};

#endif // CRACKER_H
