#include <iostream>
#include "stg.h"
using  namespace std;



int main(){
    stg cade[1] = {"hello"};
    cade[0] += " world";
    cout << cade[0].get();  
}
