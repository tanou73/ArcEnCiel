#include <iostream>
#include <math.h>
#include "Contexte.h"
#include "sha1.h"

#include <stdlib.h>
#include <time.h>

#include <iomanip>
#include <sstream>


using namespace std;

Contexte::Contexte()
{
    //ctor
    //init randoms
    srand (time(NULL));
    // notre alphabet
    //_lettres = "abcdefghijklmnopqrstuvwxyz";
    _lettres = "abcdefghijklmnopqrstuvwxyz";

    _mot_taille_min = 3;
    _mot_taille_max = 5;


    // taille de notre alphabet
    _nb_lettres = _lettres.size();

    _N = 0;
    for (int i = _mot_taille_min; i <= _mot_taille_max; ++i)
    {
        _N += pow(_nb_lettres, i);
    }

    //_N = pow(_nb_lettres, _mot_taille_max);

        // Choisir un T
   // _T = _N/2;

    cout << "alphabet : " << _lettres << endl;
    cout << "Mots de  " <<_mot_taille_min << " à " << _mot_taille_max << " lettres" << endl;
    cout << "Nombre de mots possibles = " << _N << " avec " << _nb_lettres << " lettres" << endl;


    // generer un nb aleatoire (seeder)


}

Contexte::~Contexte()
{
    //dtor
}

void Contexte::i2c( uint64_t idx, string & c )
{
    string clair = baseconvert(idx, _nb_lettres);
    c = clair;
}


string Contexte::baseconvert(uint64_t n , uint64_t base)
{

    //handle errors by returning an empty string
    if ( n < 0 || base < 2 || base > _lettres.size() )
    {
        return "";
    }

    n = n % _N;

    string s = "";
    int i = 0;
    while(true)
    {
        uint64_t r = n % base;
        s = _lettres[r] + s ;
        n = n / base;
        if ( n == 0)
            break;
        i++;
    }

    while ( s.size() < _mot_taille_min)
        s =  _lettres[0] + s;

    return s;
}



uint64_t Contexte::h2i( uint64_t t, std::string &d )
{
    uint64_t* ptr = (uint64_t*) d.c_str(); // le tableau de caractères est vu comme un tableau de grand nombre.
    uint64_t i = *ptr; // par définition le nombre stocké dans t[0-7].
    return i + t * 1 % _N;
}


uint64_t Contexte::randIndex()
{
    unsigned long n1 = random();
    unsigned long n2 = random();
    uint64_t n = ( (uint64_t) n2 )+ ( ( (uint64_t) n1 ) << 32 );
    return n;
}

void Contexte::h( std::string c, std::string &d )
{
    SHA1        sha;
    unsigned msgDigest[5];

    sha.Reset();
    sha << c.c_str();

    if (!sha.Result(msgDigest))
    {
        cerr << "ERROR-- could not compute message digest" << endl;
    }
    else
    {
        for(int i = 0; i < 5 ; i++)
        {
            stringstream buffer;
            buffer << std::hex << msgDigest[i];
            d = d + buffer.str();
        }
    }
}

uint64_t Contexte::i2i( uint64_t t, uint64_t idx )
{
    string cRes;
    string hRes;

    i2c(idx,cRes);
    h(cRes,hRes);

    return  h2i(t,hRes);
}
