#include <iostream>
#include <stdlib.h>
#include "Contexte.h"

using namespace std;

int main()
{
    // variables init
    Contexte c;

    cout << "----- i2c!" << endl;
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
    cout << i2iRes << endl;

    return 0;
}
