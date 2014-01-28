#include <iostream>
#include "Contexte.h"

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Contexte c;

    //some tests:
    string h = "gjskldgjlskmdfjgsldkmggjmldfkgndflsk";
    uint64_t i =  c.h2i(2,h);
    cout << "h2i(" << h << ") =  " << i << endl;

    uint64_t randomNumber = c.randIndex();
    cout << " a random uint64 : " << randomNumber << endl;
    return 0;
}


