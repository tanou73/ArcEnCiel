#include <iostream>
#include <stdlib.h>
#include "Contexte.h"

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    Contexte c;

    //some tests:
    string h = "azertyui";
    uint64_t i =  c.h2i(2,h);
    cout << "h2i(" << h << ") =  " << i << endl;

    uint64_t randomNumber = c.randIndex();
    cout << " a random uint64 : " << randomNumber << endl;

    string predsf;
    c.i2c(678, predsf);

    cout << " i2c " << predsf << endl;

    return 0;
}


