#include <algorithm>
#include <array>
#include <cstring>
#include <iostream>
using namespace std;

// i had to make this int a global variable LOL
int option;

// functions
char goAgain();                  // go again
int fact(int n);                 // Gets fact of N
int binomialCoeff(int n, int r); // Returns value of Binomial Coefficient
int getExNum(int num);
void example1(); // Iteration - Binomial Coefficient
void example2(); // Recursion - Binomial Coefficient
void example3(); // Space-Time Complexity - Binomial Coefficient
void example4(); // Dynamic Programming - Binomial Coefficient

// Main Function
int main() {
  char again = 'Y';

  while (again == 'y' || again == 'Y') {
    cout << "\033c";

    // list
    cout << "Unit 5 Lab - Combination" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1) Iteration - Binomial Coefficient" << endl;
    cout << "2) Recursion - Binomial Coefficient" << endl;
    cout << "3) Space-Time Complexity - Binomial Coefficient" << endl;
    cout << "4) Dynamic Programming - Binomial Coefficient" << endl;
    cout << "5) Quit Program" << endl;
    cout << "\nType in which example to view\n(1 - 4, 5 to Quit): #";

    // Option Reset
    while (!(cin >> option)) {
      cout << "\nPlease type a valid option" << endl;
      cout << "Type in which example to view\n( to Quit): #";
      cin.clear();
      cin.ignore(100, '\n');
    }

    // Switch Cases
    switch (option) {
    case 1:
      cout << "\033c";
      example1();
      again = goAgain();
      break;
    case 2:
      cout << "\033c";
      // cout << "Binomial Coefficient Equation #" << getExNum(option) << endl;
      example2();
      again =  goAgain();
      break;
    case 3:
      cout << "\033c";
      // cout << "Binomial Coefficient Equation #" << getExNum(option) << endl;
      example3();
      again = goAgain();
      break;
    case 4:
      cout << "\033c";
      // cout << "Binomial Coefficient Equation #" << getExNum(option) << endl;
      example4();
      again = goAgain();
      break;
    case 5:
      cout << "\033c";
      cout << "Thank you :)" << endl;
      return 0;
    }
  }
  cout << "\033c";
  cout << "Thank you :)" << endl;
  return 0;
}

// ============ //
//   FUNCTIONS  //
// ============ //

// go again text message
char goAgain() {
  char option;
  cout << "\nView other examples? (Y/N)" << endl;
  cout << "User Choice: ";
  cin >> option;
  return option;
}

// get example number
int getExNum(int num) { return num; }

// Returns fact of N
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++)
    res = res * i;
  return res;
}

// Returns value of Binomial Coefficient
int binomialCoeff(int n, int r) {
  // For Example 2
  if (getExNum(option) == 2) {
    // Base Cases
    if (r == 0 || r == n)
      return 1;

    // This checks if it's using the correct
    // equation for example 2
    // Remove comment below to check if true
    // cout << "EXAMPLE 2" << endl;

    // Recursive
    return binomialCoeff(n - 1, r - 1) + binomialCoeff(n - 1, r);
  }

  // For Example 3
  if (getExNum(option) == 3) {
    int res = 1;

    // Since C(n,r = C(n, n-r))
    if (r > n - r)
      r = n - r;

    // Calculate Value of
    // [n * (n-1) *---* (n-r+1)] / [r * (r-1) *---* 1]
    for (int i = 0; i < r; ++i) {
      res *= (n - i);
      res /= (i + 1);
    }

    // This checks if it's using the correct
    // equation for example 3
    // Remove comment below to check if true
    // cout << "EXAMPLE 3" << endl;

    // Space-Time Complexity
    return res;
  }

  // For Example 4
  if (getExNum(option) == 4) {
    int Coef[r + 1];
    memset(Coef, 0, sizeof(Coef));
    Coef[0] = 1;

    for (int i = 1; i <= n; i++)
      for (int j = min(i, r); j > 0; j--)
        Coef[j] = Coef[j] + Coef[j - 1];

    // This checks if it's using the correct
    // equation for example 4.
    // Remove comment below to check if true
    // cout << "EXAMPLE 4" << endl;

    return Coef[r];
  }
}

////////////////////////////////
////////////////////////////////
////////////////////////////////

// Iteration - Binomial Coefficient
void example1() {
  int n;   // n value
  int r;   // r value
  int nCr; // nCr

  // Title
  cout << "Example 1 - Iteration - Binomial Coefficient" << endl;
  cout << "--------------------------------------" << endl;

  cout << "Type in 'n' Value: ";
  cin >> n;

  cout << "Type in 'r' Value: ";
  cin >> r;

  // Calculate nCr
  nCr = fact(n) / (fact(r) * fact(n - r));

  cout << "\nC(n,r)" << endl;
  cout << "C(" << n << "," << r << ")" << endl;
  cout << "\nnCr = " << nCr << endl;
}

////////////////////////////////
////////////////////////////////
////////////////////////////////

// Recursion - Binomial Coefficient
void example2() {
  int n; // n value
  int r; // r value

  // Title
  cout << "Example 2 - Recursion - Binomial Coefficient" << endl;
  cout << "--------------------------------------" << endl;

  cout << "Type in 'n' Value: ";
  cin >> n;

  cout << "Type in 'r' Value: ";
  cin >> r;

  // Binomial Coefficient Output
  cout << "\nC(n,r)" << endl;
  cout << "C(" << n << "," << r << ")" << endl;
  cout << "\nBinomial Coefficient: " << binomialCoeff(n, r) << endl;
}

////////////////////////////////
////////////////////////////////
////////////////////////////////

// Space-Time Complexity - Binomial Coefficient
void example3() {
  int n; // n value
  int r; // r value

  // Title
  cout << "Example 3 - Space-Time Complexity - Binomial Coefficient" << endl;
  cout << "--------------------------------------" << endl;

  cout << "Type in 'n' Value: ";
  cin >> n;

  cout << "Type in 'r' Value: ";
  cin >> r;

  // Binomial Coefficient Output
  cout << "\nC(n,r)" << endl;
  cout << "C(" << n << "," << r << ")" << endl;
  cout << "\nBinomial Coefficient: " << binomialCoeff(n, r) << endl;
}

////////////////////////////////
////////////////////////////////
////////////////////////////////

// Dynamic Programming - Binomial Coefficient
void example4() {
  int n; // n value
  int r; // r value

  // Title
  cout << "Example 4 - Dynamic Programming - Binomial Coefficient" << endl;
  cout << "--------------------------------------" << endl;

  cout << "Type in 'n' Value: ";
  cin >> n;

  cout << "Type in 'r' Value: ";
  cin >> r;

  // Binomial Coefficient Output
  cout << "\nC(n,r)" << endl;
  cout << "C(" << n << "," << r << ")" << endl;
  cout << "\nBinomial Coefficient: " << binomialCoeff(n, r) << endl;
}
