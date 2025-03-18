#include <iostream>
using namespace std;

void encrypted(char *, int);
void decrypted(char *, int);

int main() {
  char msg[100];
  int key, pick;

  cout << "Encrypt (1) or Decrypt (2) message?: ";
  cin >> pick;
  cin.clear();
  cin.ignore();

  if (pick == 1)
    cout << "Enter a message to encrypt: ";
  else if (pick == 2)
    cout << "Enter a message to decrypt: ";

  cin.getline(msg, 100);
  cout << "\nEnter shift value: ";
  cin >> key;

  if (pick == 1) {
    encrypted(msg, key);
    cout << "\nEncrypted Message: \"" << msg << "\"";
  } else if (pick == 2) {
    decrypted(msg, key);
    cout << "\nDecrypted Message: \"" << msg << "\"";
  }

  return 0;
}

// Encrypt
void encrypted(char *msg, int key) {
  char ch;
  for (int i = 0; msg[i] != '\0'; ++i) {
    ch = msg[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = ch + key;

      if (ch > 'z')
        ch = ch - 'z' + 'a' - 1;

      msg[i] = ch;
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = ch + key;

      if (ch > 'Z')
        ch = ch - 'Z' + 'A' - 1;

      msg[i] = ch;
    }
  }
}

// Decrypt
void decrypted(char *msg, int key) {
  char ch;
  for (int i = 0; msg[i] != '\0'; ++i) {
    ch = msg[i];
    if (ch >= 'a' && ch <= 'z') {
      ch = ch - key;

      if (ch > 'z')
        ch = ch + 'z' - 'a' + 1;

      msg[i] = ch;
    } else if (ch >= 'A' && ch <= 'Z') {
      ch = ch - key;

      if (ch > 'Z')
        ch = ch + 'Z' - 'A' + 1;

      msg[i] = ch;
    }
  }
}