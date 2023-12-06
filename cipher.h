#include <iostream>
#include <string>

// cipherType class
class cipherType {
private:
  std::string plain_text;
  int key_shift;
  std::string cipher_text;

public:
  cipherType();

  cipherType(std::string);

  cipherType(std::string, int);

  void setParameters(std::string, int);

  /*
  encrypts plain_text using key_shift number of shifts and stores
  the result in cipher_text.
  encrypted characters must wrap around after 'z' i.e., 'w' shifted
  by 4 positions in the alphabet gives 'a'. Similarly, 'y' shifted
  by 3 positions gives 'b'.
  Hint: You can manually apply wrap around, or you can use the formula:
  'E = (x + n) mod 26' to apply wrap around.
  x is the position of char being encrypted in the alphabet i.e.,
  a = 1, b = 2, c = 3,...
  n is the key shift
  then, E is the number of shifts needed from 'a' to encrypt the character.
  */
  void encrypt();

  std::string getPlainText();

  int getKeyShift();

  std::string getCipherText();
};

// write your class method implementations here

cipherType::cipherType() {
  plain_text = "";
  cipher_text = "";
  key_shift = 0;
}

cipherType::cipherType(std::string s) {
  plain_text = s;
  cipher_text = "";
  key_shift = 0;
}

cipherType::cipherType(std::string s, int shift) {
  plain_text = s;
  key_shift = shift;
  encrypt();
}

void cipherType::setParameters(std::string s, int shift) {
  plain_text = s;
  key_shift = shift;
  encrypt();
}

void cipherType::encrypt() {
  std::string encrypted = "";
  char encryptedChar = ' ';
  for (int i = 0; i < plain_text.length(); i++) {
    if (plain_text[i] >= 'a' && plain_text[i] <= 'z') {
      encryptedChar = 'a' + char(((int(plain_text[i]) - 'a') + key_shift) % 26);
      encrypted += encryptedChar;
    } else if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
      encryptedChar = 'A' + char(((int(plain_text[i]) - 'A') + key_shift) % 26);
      encrypted += encryptedChar;
    } else
      encrypted += plain_text[i];
  }
  cipher_text = encrypted;
}

std::string cipherType::getPlainText() { return plain_text; }

int cipherType::getKeyShift() { return key_shift; }

std::string cipherType::getCipherText() { return cipher_text; }
