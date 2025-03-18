#include <iostream>
#include <string>
using namespace std;

string Encrypt(string, int);

int main(int argc, char *argv[]) {
  string s;
  int key;

  cout << "Input Message: ";
  getline(cin, s);

  cout << "\nInput Shift Key: ";
  cin >> key;

  cout << "\nEncrypted Message: " << Encrypt(s, key) << endl;
}

// encrypt string
string Encrypt(string s, int key) {
  string cypt = s;
  for (int curr = 0; curr < s.length(); curr++)
      cypt[curr] += key;

  return cypt;
}