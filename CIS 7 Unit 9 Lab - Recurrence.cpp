#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
using namespace std;

// Global Variables
int option;

// Function Prototypes
int fib(int n);
int factorial(int n);

// Example Functions
void example1();
void example2();
void example3();
void example4();

// Utility Functions
char goAgain();

// Main Function
int main() {
  char again = 'Y';

  while (again == 'y' || again == 'Y') {
    cout << "\033c";

    // list
    cout << "Unit 9 Lab - Recurrence in C++" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1) Fibonacci Sequence" << endl;
    cout << "2) Fibonacci Sequence (Optimized)" << endl;
    cout << "3) Fibonacci Sequence (Array)" << endl;
    cout << "4) Linear Recurrence Relations (Recursive Function)" << endl;
    cout << "5) Quit Program" << endl;
    cout << "\nType in which example to view\n(1-4, 5 to Quit): #";

    // Option Reset
    while (!(cin >> option)) {
      cout << "\nPlease type a valid option" << endl;
      cout << "Type in which example to view\n(1-4, 5 to Quit): #";
      cin.clear();
      cin.ignore(100, '\n');
    }

    // Switch Cases
    switch (option) {
    case 1:            // Fibonacci Sequence
      cout << "\033c"; // This clears the console (at least on replit)

      // Title
      cout << "Example 1) Fibonacci Sequence" << endl;
      cout << "-----------------------------------------------" << endl;

      example1();
      again = goAgain();
      break;
    case 2: // Fibonacci Sequence (Optimized)
      cout << "\033c";

      // Title
      cout << "Example 2) Fibonacci Sequence (Optimized)" << endl;
      cout << "-----------------------------------------------" << endl;

      example2();
      again = goAgain();
      break;
    case 3: // Fibonacci Sequence (Array)
      cout << "\033c";

      // Title
      cout << "Example 3) Fibonacci Sequence (Array)" << endl;
      cout << "-----------------------------------------------" << endl;

      example3();
      again = goAgain();
      break;
    case 4: // Linear Recurrence Relations (Recursive Function)
      cout << "\033c";

      // Title
      cout << "Example 4) Linear Recurrence Relations (Recursive Function)"
           << endl;
      cout << "-----------------------------------------------" << endl;

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

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Fibonacci Options
int fib(int n) {
  // Initial Fibonacci Sequence
  if (option == 1) {
    // cout << "OPTION 1" << endl;
    if (n <= 1)
      return n;
    return fib(n - 1) + fib(n - 2);
  }

  // Fibonacci Sequence (Optimized)
  if (option == 2) {
    // cout << "OPTION 2" << endl;
    int a = 0, b = 1, c, i;
    if (n == 0)
      return a;
    for (i = 2; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return b;
  }

  // Fibonacci Sequence (Array)
  if (option == 3) {
    // cout << "OPTION 3" << endl;

    // Declare an Array to Store Fibonacci Numbers
    int f[n + 2]; // 1 Extra to Handle Csae, n = 0
    int i;

    // 0th and 1st number of the Series are 0 and 1
    f[0] = 0;
    f[1] = 1;

    for (i = 2; i <= n; i++) {
      // Add the previous 2 numbers in series
      // and Store it
      f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
  }
}

// Factorial
int factorial(int n) {
  if (n > 1)
    return n * factorial(n - 1);
  else
    return 1;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

void example1() {
  int n;
  cout << "n = ";
  cin >> n;

  cout << "\nYour Fibonacci Sequence: " << fib(n) << endl;
}

void example2() {
  int n;
  cout << "n = ";
  cin >> n;

  cout << "\nYour Fibonacci Sequence: " << fib(n) << endl;
}

void example3() {
  int n;
  cout << "n = ";
  cin >> n;

  cout << "\nYour Fibonacci Sequence: " << fib(n) << endl;
}

void example4() {
  int n;
  cout << "n = ";
  cin >> n;

  cout << "\nFactorial of: " << n << " = " << factorial(n) << endl;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////