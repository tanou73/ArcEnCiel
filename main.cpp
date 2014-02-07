#include <iostream>
#include <stdlib.h>
#include "Contexte.h"
#include "ArcEnCiel.h"
#include "Cracker.h"

using namespace std;

int main()
{
    /*****************
    /* Contexte
    /*****************/
    Contexte c;

    /*cout << "----- i2c!" << endl;
    string i2cRes;
    c.i2c(678, i2cRes);
    cout << i2cRes << endl;

    cout << "----- c2h!" << endl;
    string c2hRes;
    c.h("abc", c2hRes);
    cout << c2hRes << endl;

    cout << "----- h2i!" << endl;
    uint64_t h2iRes;
    h2iRes = c.h2i(2, c2hRes);
    cout << h2iRes << endl;

    cout << "----- i2i!" << endl;
    uint64_t i2iRes;
    i2iRes = c.i2i(678);
    cout << i2iRes << endl;*/

    /*****************
    /* Arc en ciel
    /*****************/
    // on init notre AEC et on creer notre table

    int m = 100000;
    int t = 1000;
    string file = "dict";

    int choice = 0;

    cout << "Que voulez-vous faire ? "<< endl;
    cout << "1. Générer la table avec M = " << m << " et T = " << t << " dans le fichier " << file << ".koin" <<  endl;
    cout << "2. Charger le fichier " << file << ".koin" << endl;


    cin >> choice;
    cout << "Veuillez patienter..." << endl;
    ArcEnCiel aec;
    switch (choice)
    {
        case 1 :
            aec.creer(c, m, t);
            aec.trier();
            aec.save(file);
        break;
        case 2:
             aec.load(file);
        break;
        default:
            cout << "Mauvaise entrée saisie" << endl;
            exit(0);
        break;
    }

    cout << "choix : " << choice << endl;

    cout << "Veuillez entrer le texte crypté en SHA1 à déchiffer  : " << endl;

    string sha1;
    string uncrypted = "--non trouvé--";

    cin >> sha1;
    cout << "Veuillez patienter..." << endl;

    Cracker crack;
    if ( crack.cracker(sha1, aec, c, uncrypted))
    {
        cout << "Mot de passe trouvé: " << uncrypted << endl;
    }
    else
    {
     cout << "Le mot de passe ne se trouve pas dans la table :( " << endl;
    }
    cout << "Entrez 0 pour quitter le programme" << endl;
    cin >> choice;
/*

    ArcEnCiel aec(c, m, t);
    aec.trier();
    aec.save("test3");

    //load
    //ArcEnCiel aec(c, "test");

    string lol;
    string hash = "e78543ddc3a9383ccaf39bcf2de76abcec261e69";
    Cracker crack;
    crack.cracker(hash, aec, c, lol);
    cout << "YOLO LOL BOB OMGGGOOOOODDD    " << lol << endl;


    */
    return 0;
}
