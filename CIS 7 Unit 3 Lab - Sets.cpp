#include <iostream>
#include <set>
using namespace std;

char goAgain();
void example1(); // Insert Element
void example2(); // Iterator - Begin
void example3(); // Clear Content
void example4(); // Empty Set

// Main Function
int main() {
  int option;
  char again = 'Y';

  while (again == 'y' || again == 'Y') {
    cout << "\033c";

    // list
    cout << "Unit 3 Lab - Sets" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1) Insert Element" << endl;
    cout << "2) Iterator - Begin" << endl;
    cout << "3) Clear Content" << endl;
    cout << "4) Empty Set" << endl;
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

// Insert Element
void example1() {
  // Title
  cout << "Example 1) Insert Element" << endl;
  cout << "--------------------------------------" << endl;

  // Set variables
  set<int> myset;
  set<int>::iterator it;
  pair<set<int>::iterator, bool> ret;

  // set initial values:
  for (int i = 1; i <= 5; ++i)
    myset.insert(i * 10);
  ret = myset.insert(60); // no new element inserted

  // output 1
  cout << "(BEFORE INSERT) myset contains: ";
  for (it = myset.begin(); it != myset.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';
  
  // "it" points to element 20
  if (ret.second == false)
    it = ret.first;
  
  myset.insert(it, 36); // max efficiency inserting
  myset.insert(it, 54); // max efficiency inserting
  myset.insert(it, 12); // no max efficiency inserting

  int myints[] = {3, 21, 37}; // 10 already in set, not inserted
  myset.insert(myints, myints + 3);

 // output 2
 cout << "(INSERT 1) myset contains: ";
  for (it = myset.begin(); it != myset.end(); ++it)
    cout << ' ' << *it;
  cout << '\n'; 

  // myset.insert(it, 30);
  // myset.insert(it, 40);
  // myset.insert(it, 50);
  // myset.insert(it, 60);
  
  // output 3
  // cout << "(INSERT 2) myset contains: ";
  // for (it = myset.begin(); it != myset.end(); ++it)
  //   cout << ' ' << *it;
  // cout << '\n';
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Iterator - Begin
void example2() {

  // Title
  cout << "Example 2) Iterator - Begin" << endl;
  cout << "--------------------------------------" << endl;

  // variables
  // int myints[] = {33, 23, 65, 42, 13};
  int myints[] = {};
  set<int> myset(myints, myints + 5);

  // output
  cout << "myset contains: ";
  for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    cout << ' ' << *it;
  cout << "\n";
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Clear Content
void example3() {

  // Title
  cout << "Example 3) Clear Content" << endl;
  cout << "--------------------------------------" << endl;

  // variables
  set<int> myset;
  myset.insert(100);
  myset.insert(200);
  myset.insert(300);

  // output 1
  cout << "(BEFORE) myset contains: ";
  for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    cout << ' ' << *it;
  cout << "\n";

  // insert different new element
  // myset.clear();
  myset.insert(0);
  myset.insert(1101);
  myset.insert(2202);

  // output 2
  cout << "(AFTER) myset contains: ";
  for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    cout << ' ' << *it;
  cout << "\n";
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Empty Set
void example4() {

  // Title
  cout << "Example 4) Empty Set" << endl;
  cout << "--------------------------------------" << endl;

  // variables
  set<int> myset;
  myset.insert(20);
  myset.insert(30);
  myset.insert(10);

  // output 1
  cout << "myset contains: ";
  while (!myset.empty()) {
    cout << ' ' << *myset.begin();
    myset.erase(myset.begin());
  }
  cout << "\n";
}