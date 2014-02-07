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
    string file = "big-dic";

    cout << "Entrez un nom de fichier [tapez " << file << " si vous voulez prendre celui par défaut] : ";
    cin >> file;

    int choice = 0;
    cout << "Que voulez-vous faire ? "<< endl;
    cout << "1. Générer la table dans le fichier " << file << ".koin" <<  endl;
    cout << "2. Charger le fichier " << file << ".koin" << endl;


    cin >> choice;
    ArcEnCiel aec;
    switch (choice)
    {
        case 1 :
            cout << endl << endl << "Choisissez une taille de table M : ";
            cin >> m;
            cout << endl << endl << "Choisissez une largeur d'arc T : ";
            cin >> t;

            cout << endl << endl << "Veuillez patienter... (sortez vous acheter des pop-corns et regardez la dernière saison de californication..)" << endl;

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

    cout << endl << endl << "Veuillez entrer le texte crypté en SHA1 à déchiffer  : " << endl;

    string sha1;
    string uncrypted = "--non trouvé--";

    cin >> sha1;
    cout << "Veuillez patienter... (cette fois c'est rapide... normalement... parfois... ça dépend..)" << endl;

    Cracker crack;
    if ( crack.cracker(sha1, aec, c, uncrypted))
    {
        cout << "Mot de passe trouvé: " << uncrypted << endl;
    }
    else
    {
     cout << endl << endl << "Le mot de passe ne se trouve pas dans la table :( C'est pas la taille qui compte mais quand même plus c'est gros mieux c'est... " << endl;
    }
    cout << endl << "Entrez n'importe quoi pour quitter le programme" << endl;
    cin >> choice;

    return 0;
}
