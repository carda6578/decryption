#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cipher.h"

using namespace std;

int main() {
    char cipherText[100];

    cipherType newCipher;
    ifstream infile;
    infile.open("unknown_msg.dat");
    infile >> cipherText;
    cout << cipherText << endl;

    cout << newCipher.getPlainText() << endl;

    return 0;
}
