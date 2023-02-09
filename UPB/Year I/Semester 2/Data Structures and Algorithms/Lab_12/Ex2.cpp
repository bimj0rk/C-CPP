//2
#include <iostream>
#include <stdlib.h>
#include "../DSA_Headers/hash.h"
#define VMAX 17
#define P 13

using namespace std;

int hfunc(string key) {
    int hkey = 0;
    string num;

    for(int i = key.length() - 4; i < key.length(); i++)
        num += key[i];

    hkey = stoi(num);
    hkey = (hkey - 4000) * 1.6694;

    return hkey;
}

Hashtable<string, double> hid(VMAX, hfunc);

int main(){
    hid.put("5009100019990", 10);
    cout << "Value of a certain key(5009100019990): " << hid.get("50009100019990");
}