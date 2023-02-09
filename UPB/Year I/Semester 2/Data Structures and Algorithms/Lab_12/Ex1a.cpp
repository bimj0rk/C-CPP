//1a
#include <iostream>
#include <stdlib.h>
#include "../DSA_Headers/hash.h"
#define VMAX 17
#define P 13
using namespace std;

int hfunc(string key) {
    int hkey = 0;
    for (int i = 0; i < key.length(); i++)
        hkey = (hkey * P + key[i]) % VMAX;
    return hkey;
}

Hashtable<string, double> hid(VMAX, hfunc);

int division(string key){
    int sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += int(key[i]);
    
    return sum%VMAX;
}

int main(){
    int n = 11;
    hid.put("1", 113);
    hid.put("2", 117);
    hid.put("3", 97);
    hid.put("4", 100);
    hid.put("5", 114);
    hid.put("6", 108);
    hid.put("7", 116);
    hid.put("8", 105);
    hid.put("9", 99);
    hid.put("10", 0);
    hid.put("11", 0);

    cout << division("1") << endl;
    cout << division("2") << endl;
    cout << division("3") << endl;
    cout << division("4") << endl;
    cout << division("5") << endl;
    cout << division("6") << endl;
    cout << division("7") << endl;
    cout << division("8") << endl;
    cout << division("9") << endl;
    cout << division("10") << endl;
    cout << division("11") << endl;

    
	return 0;
}

