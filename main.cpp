#include <iostream>
#include "stg.h"
using  namespace std;


int main(){
    stg e = "textual ";
    e += "nuevo texto";

    cout << e.get() << "\nconsegir una localidad: por ejemplo : " << e.getLoc(6,e.length()-6);
}
