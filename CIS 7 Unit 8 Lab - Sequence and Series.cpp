#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
using namespace std;

// Global Variables
int option;

// Function Prototypes
int Nth_of_AP(int, int, int); // Determine Nth term in Arithmetic Progression
int sumOfAP(int, int, int);   // Find sum of Arithmetic Sequence
double example3(double, double, double, double, double,
                double);    // Find Arithmetic Series from Input
int sumOfGP(int, int, int); // Calculate Sum of Geometryic Sequence
double db_sumOfGP(double a, double r, double n); // ^^ Double

// Utility Functions
char goAgain();

// Main Function
int main() {
  char again = 'Y';
  float a, r, d, n, N, i, sum, j;

  while (again == 'y' || again == 'Y') {
    cout << "\033c";

    // list
    cout << "Unit 8 Lab - Sequence and Series" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1) Arithmetic Sequence" << endl;
    cout << "2) Arithmetic Series" << endl;
    cout << "3) Arithmetic Series (with User Input)" << endl;
    cout << "4) Geometric Sequence and Series" << endl;
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
    case 1:            // Arithmetic Sequence
      cout << "\033c"; // This clears the console (at least on replit)

      // Title
      cout << "Example 1) Arithmetic Sequence" << endl;
      cout << "-----------------------------------------------" << endl;

      // Function
      a = 1;  // starting number
      d = 7;  // common difference
      N = 15; // Nth term to be found

      cout << "a: " << a << endl;
      cout << "d: " << d << endl;
      cout << "N: " << N << endl << endl;
      
      // Output Display
      Nth_of_AP(a, d, N);
      cout << endl;
      again = goAgain();
      break;
    case 2: // Arithmetic Series
      cout << "\033c";

      // Title
      cout << "Example 2) Arithmetic Series" << endl;
      cout << "-----------------------------------------------" << endl;

      // Function
      n = 30;
      a = 4;
      d = 10;
      sum = 0;

      cout << "a: " << a << endl;
      cout << "d: " << d << endl;
      cout << "n: " << n << endl << endl;
      
      // Output Display
      sumOfAP(a, d, n);
      again = goAgain();
      break;
    case 3: // Arithmetic Series with user input
      cout << "\033c";

      // Title
      cout << "Example 3) Arithmetic Series w/ User Input" << endl;
      cout << "-----------------------------------------------" << endl;

      // Function
      example3(a, d, n, i, sum, j);
      again = goAgain();
      break;
    case 4: // Geometric Sequence and Series
      cout << "\033c";

      // Title
      cout << "Example 4) Geometric Sequence and Series" << endl;
      cout << "-----------------------------------------------" << endl;

      // Function
      a = 1;
      r = 3;
      n = 7;

      cout << "a: " << a << endl;
      cout << "r: " << r << endl;
      cout << "n: " << n << endl << endl;

      // Output
      // sumOfGP(a,r,n); // UNCOMMENT FOR INTS
      db_sumOfGP(a, r, n); // DOUBLES / FLOATS
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

// Arithmetic Progression
int Nth_of_AP(int a, int d, int N) {

  // Display Sequence
  for (int i = 1; i <= N; i++) // This for loop outputs the sequence
    cout << (a + (i - 1) * d) << " ";

  // using formula to find the
  // Nth term t(n) = a(1) + (n-1)*d

  // Output
  cout << "\nThe " << N << "th term of the series is: " << (a + (N - 1) * d);
  return (a + (N - 1) * d);
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Arithmetic Sequence
int sumOfAP(int a, int d, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cout << sum << " + " << a;
    sum = sum + a;
    a = a + d;
    cout << " = " << sum << endl;
  }
  cout << "Arithmetic Sequence Sum: " << sum << endl;
  return sum;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Arithmetic Series from Input
double example3(double a, double d, double n, double i, double sum, double j) {
  cout << "Enter Starting Value (a): ";
  cin >> a;

  cout << "Enter Difference (d): ";
  cin >> d;

  cout << "Enter the Nth term (n): ";
  cin >> n;

  cout << endl;
  for (int i = a; i < ((n)*d + a); i += d) {
    sum += i;
    cout << i << " ";
  }
  cout << "\nThe sum of your Arithmetic Series is: " << sum << endl;
  return sum;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Sum of Geometric Series
int sumOfGP(int a, int r, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cout << sum << " + " << a;
    sum = sum + a;
    a = a * r;
    cout << " = " << sum << endl;
  }
  cout << "\nGeometric Sequence Sum: " << sum << endl;
  return sum;
}

// Sum of Geometric Series (DOUBLE)
double db_sumOfGP(double a, double r, double n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    cout << sum << " + " << a;
    sum = sum + a;
    a = a * r;
    cout << " = " << sum << endl;
  }
  cout << "\nGeometric Sequence Sum: " << sum << endl;
  return sum;
}