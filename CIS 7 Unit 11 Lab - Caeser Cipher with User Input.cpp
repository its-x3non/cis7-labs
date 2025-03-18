#include <iostream>
#include <string>

using namespace std;

char caesar(char);

int main() {
  string input;
  do {
    cout << "\033c";
    cout << "Enter Cipher Text (Blank Line + Enter to Quit)" << endl;
    cout << "Cipher Text: ";
    getline(cin, input);

    string output = "";
    for (int x = 0; x < input.length(); x++)
      output += caesar(input[x]);

    if (input.length() > 0) {
      cout << "\nCiphered Text: \"" << output << "\"" << endl;
      cout << "\nPress Enter to Continue";
      cin.get();
    } else
      return 0;

  } while (input.length() != 0);
  return 0;
}

char caesar(char c) {
  if (isalpha(c)) {
    c = toupper(c); // use toupper to prevent case sensitivity
    c = (((c - 65) + 13) % 26) + 65;
  }

  // if c isn't alpha, return c
  return c;
}