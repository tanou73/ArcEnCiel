#include <iostream>
#include <stdlib.h>
#include "Contexte.h"
#include "ArcEnCiel.h"

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
    ArcEnCiel aec(c, 10, 3);
    // on trie notre table
    cout << "\n" << "----- Trie!" << endl;
    aec.trier();


    cout << "\n" << "----- Rech.Dicho!" << endl;
    uint64_t toFind = aec.getX(3).idxT;
    uint64_t idx1;
    uint64_t idxT;
    if (aec.recherche(toFind, idx1, idxT))
        cout << idx1 << " - " << idxT << endl;
    else
        cout << "something went wrong" << endl;

    aec.save("test");

    ArcEnCiel aec2(c, "test");

    return 0;
}
