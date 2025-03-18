// CIS 7
// Fall 2023
// Unit 2 Lab - Bitwise, Logical Operators and Boolean Values

#include <iostream>
#include <iomanip>
using namespace std;

// Functions
char goAgain(); // repeat program text
void example1(); // Bitwise Operator Program
void example2(); // Using Boolean Variables to Evaluate TRUE and !TRUE
void example3(); // boolalpha function
void example4(); // Logical NOR Operator
void example5(); // Logical && Operator

// Main Function
int main() {
  int option;
  char again = 'Y';

  while(again == 'y' || again == 'Y')
    { 
      cout << "\033c";

      // list
      cout << "Unit 2 Lab - Bitwise, Logical Operators and Boolean Values" << endl;
  cout << "--------------------------------------" << endl;
  cout << "1) Bitwise Operator" << endl;
  cout << "2) Using Bool Variables to Evaluate TRUE and !TRUE" << endl;
  cout << "3) Boolalpha Function" << endl;
  cout << "4) Logical NOR Operator" << endl;
  cout << "5) Logical && Operator" << endl;
  cout << "6) Quit Program" << endl;
  cout << "\nType in which example to view\n(1-5, 6 to Quit): #";

  // Option Reset
  while(!(cin >> option))
    {
      cout << "\nPlease type a valid option" << endl;
      cout << "Type in which example to view\n(1-5, 6 to Quit): #";
      cin.clear();
      cin.ignore(100, '\n');
    }

  // Switch Cases
  switch(option)
    {
    case 1:
      cout << "\033c"; // This clears the console (at least on replit)
      example1();
      again = goAgain();
      break;
    case 2:
      cout << "\033c";
      example2();
      again = goAgain();
      break;
    case 3:
      cout << "\033c";
      example3();
      again = goAgain();
      break;
    case 4:
      cout << "\033c";
      example4();
      again = goAgain();
      break;
    case 5:
      cout << "\033c";
      example5();
      again = goAgain();
      break;
    case 6:
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
char goAgain()
{
  char option;
  cout << "\nView other examples? (Y/N)" << endl;
  cout << "User Choice: ";
  cin >> option;
  return option;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Bitwise Operator Program
void example1()
{
  unsigned int P = 40;
  unsigned int Q = 17;
  int R = 0;

  // Title
  cout << "Example 1) Bitwise Operator Program" << endl;
  cout << "--------------------------------------" << endl;

  // Variables
  cout << "P = " << P << endl;
  cout << "Q = " << Q << endl;
  
  // Output
  R = P & Q; // 0
  cout << "\nResult for P & Q: " << R << endl;
  
  R = P | Q; // 57 -> 0011 1001
  cout << "Result for P | Q: " << R << endl;
  
  R = P ^ Q; // 57 -> 0011 1001
  cout << "Result for P ^ Q: " << R << endl;

  R = ~P;
  cout << "Result for ~P: " << R << endl;

  R = ~(P & Q);
  cout << "Result for ~(P & Q): " << R << endl;

  R = ~(P | Q);
  cout << "Result for ~(P | Q): " << R << endl;

  R = P << 3; // 320 -> 0001 0100 0000
  cout << "Result for P << 3: " << R << endl;

  R = P >> 3; // 5 -> 0101
  cout << "Result for P >> 3: " << R << endl;
  
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Using Boolean Variables to Evaluate TRUE and !TRUE
void example2()
{
  // Title
  cout << "Example 2) Program using Boolean Variables to evaluate TRUE and !TRUE" << endl;
  cout << "--------------------------------------" << endl;
  
  // False Values
  cout << "False: " << false << endl;
  cout << "Not False (True): "<< !false << endl;
  
  cout << endl;
  // Bool Operator
  bool b(true);
  cout << "True: " << b << endl;
  cout << "Not True (False): " << !b << endl;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Boolalpha function
void example3()
{
  // Title
  cout << "Example 3) std::boolalpha to print “true” or “false”" << endl;
  cout << "--------------------------------------" << endl;
  
  // variables
  bool b1;
  int x = 24;
  int e = 20;

  
  // example 1 
  cout << "24 > 20: ";
  if(x > e)
  {
    b1 = true;
    cout << boolalpha << b1 << endl;
  }
  else
  {
    b1 = false;
    cout << noboolalpha << b1 << endl;
  }

  // example 2 (too lazy to make more statements)
  // just change values or something
  cout << "\n24 != 20: ";
  if(x != e)
  {
    b1 = true;
    cout << boolalpha << b1 << endl;
  }
  else
  {
    b1 = false;
    cout << noboolalpha << b1 << endl;
  }
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Logical NOR Operator
void example4()
{
  int credits;
  int semesters;

  // Title
  cout << "Example 4) Logical NOR Operator " << endl;
  cout << "--------------------------------------" << endl;
  
  // Ask for credits
  cout << "How much credits have you completed?\nCredits: ";
  cin >> credits;

  cout << endl;
  
  // Ask for semesters
  cout << "How much semesters have you completed?\nSemesters: ";
  cin >> semesters;
  
  // Clear Console
  cout << "\033c";

  // Title
  cout << "Example 4) Logical NOR Operator " << endl;
  cout << "--------------------------------------" << endl;
  
  // Determine if Student gets Associates Degree
  if(!(credits > 60 || semesters > 5))
  {
    cout << "You have not earned an associates degree as you \nhave completed less than 60 credits or\nyou have done less than 5 semesters.\n" << endl;
    cout << "Information Given:" << endl;
    cout << "Credits: " << credits << endl;
    cout << "Semesters: " << semesters << endl;
  } 
  else
  {
    cout << "You have earned an associates degree!\nCongratulations! :)\n" << endl;
    cout << "Information Given:" << endl;
    cout << "Credits: " << credits << endl;
    cout << "Semesters: " << semesters << endl;
  }
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Logical && Operator
void example5()
{
  int age;
  string ageMet;
  int yearsDriving;
  string ydMet;

  // Title
  cout << "Example 5) Logical && (and) Operator " << endl;
  cout << "--------------------------------------" << endl;
  
  // Ask for age
  cout << "How old are you?\nAge: ";
  cin >> age;

  cout << endl;
  
  // Ask for driving years
  cout << "How many years have you been driving for?\nYears Driven: ";
  cin >> yearsDriving;

  // Clear Console
  cout << "\033c";

  // Age Check
  if(age >= 21)
    ageMet = " [Requirement Met (21+ y/o)]";
  else
    ageMet = " [Requirement Not Met (21+ y/o)]";

  // Years Driving Check
  if(yearsDriving >= 5)
    ydMet = " [Requirement Met (5+ years)]";
  else
    ydMet = " [Requirement Not Met (5+ years)]";

  // Title
  cout << "Example 5) Logical && (and) Operator " << endl;
  cout << "--------------------------------------" << endl;
  
  // Check if requirements met
  if(age >= 21 && yearsDriving >= 5)
  {
    cout << "Congratulations!\nYou're able to get a car insurance discount!\n" << endl;
    cout << "Information Given:" << endl;
    cout << "Age: " << age << ageMet << endl;
    cout << "Years Driven: " << yearsDriving << ydMet << endl;
  }
  else
  {
    cout << "You have not met the requirements to get a car insurance discount :(\n" << endl;
    cout << "Information Given:" << endl;
    cout << "Age: " << age << ageMet << endl;
    cout << "Years Driven: " << yearsDriving << ydMet << endl;
  }
}
