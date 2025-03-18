#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char goAgain();
void example1(); // next_permutation in Algorithm STL
void example2(); // prev_permutation in Algorithm STL
void example3(); // is_permutation in Algorithm STL
void permute(string str, string out); // Permutation String with Function

// Main Function
int main() {
  int option;
  char again = 'Y';
  string str = "ABCDEF";

  while (again == 'y' || again == 'Y') {
    cout << "\033c";

    // list
    cout << "Unit 4 Lab - Permutation" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1) next_permutation in Algorithm STL" << endl;
    cout << "2) prev_permutation in Algorithm STL" << endl;
    cout << "3) is_permutation in Algorithm STL" << endl;
    cout << "4) Permutation String with Function" << endl;
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
    case 1: // next
      cout << "\033c";
      example1();
      goAgain();
      break;
    case 2: // prev
      cout << "\033c";
      example2();
      goAgain();
      break;
    case 3: // is
      cout << "\033c";
      example3();
      goAgain();
      break;
    case 4: // permutation
      cout << "\033c";
      // Title
      cout << "Example 4) Permutation String with Function" << endl;
      cout << "--------------------------------------------" << endl;
      
      // function
      permute(str, "");
      
      goAgain();
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

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////

// next_permutation in Algorithm STL
void example1() {
   // Title
  cout << "Example 1) next_permutation in Algorithm STL" << endl;
  cout << "--------------------------------------------" << endl;

  // variables
  // int arr[] = {1, 2, 3, 4}
  int arr[] = {21, 22, 3, 4};
  

  // sort(myints,myints+4);
  
  cout << "The 4! possible permutations with 4 elements:\n"; 

  // da loop
  int i = 1;
  do { 
      cout << i << ": " <<arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << endl;
    i++;
  } while (next_permutation(arr, arr + 4)); 

  // after da loop
  cout << "After loop: " << arr[0] << ' ' << arr[1] << ' ' << arr[2] << ' ' << arr[3] << '\n'; 
}

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////

// prev_permutation in Algorithm STL
void example2() {
   // Title
  cout << "Example 2) prev_permutation in Algorithm STL" << endl;
  cout << "--------------------------------------------" << endl;

  // variables
  // int myints[] = {1, 2, 3, 4};
  int myints[] = {11, 12, 13, 4};

  // sort(myints,myints+4);
  reverse(myints,myints+4);

  // text
  cout << "The 4! possible permutations with 4 elements:" << endl;

  // loop
  int i = 1;
  do {
    // print the elements in the array
    cout << i << ": " << myints[0] << ' ' << myints[1] << ' ' << myints[2]
         << ' ' << myints[3] << endl;
    i++;
  } while (prev_permutation(myints, myints + 4));

  cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2]
       << ' ' << myints[3] << endl;

///////////////////////////////
///// Code for 5 elements /////
///////////////////////////////

  // // variables
  // // int myints[] = {1, 2, 3, 4, 5};

  // // sort(myints,myints+5);
  // reverse(myints,myints+5);

  // // text
  // cout << "The 5! possible permutations with 5 elements:" << endl;

  // // loop
  // int i = 1;
  // do {
  //   // print the elements in the array
  //   cout << i << ": " << myints[0] << ' ' << myints[1] << ' ' << myints[2]
  //        << ' ' << myints[3] << ' ' << myints[4] << endl;
  //   i++;
  // } while (prev_permutation(myints, myints + 5));

  // cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2]
  //      << ' ' << myints[3] << ' ' << myints[4] << endl;
}

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////

// is_permutation in Algorithm STL
void example3() {
   // Title
  cout << "Example 3) is_permutation in Algorithm STL" << endl;
  cout << "--------------------------------------------" << endl;

   // Define two arrays with the same elements in different order
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 4, 99, 2, 1};

 // display array 1
  cout << "arr1: ";
  for(int i = 0; i < 5; i++)
      cout << arr1[i] << " ";
  cout << endl;

  // display array 2
  cout << "arr2: ";
  for(int i = 0; i < 5; i++)
      cout << arr2[i] << " ";
  cout << endl << endl;
  
    // Check if arr2 is a permutation of arr1
    if (is_permutation(arr1, arr1 + 5, arr2)) {
        cout << "arr2 is a permutation of arr1" << endl;
    } else {
        cout << "arr2 is not a permutation of arr1" << endl;
    }
}

//////////////////////////////////
//////////////////////////////////
//////////////////////////////////

// permutation string with function
void permute(string str, string out)
{
  // When size of str becomes 0, out has a
  // permutaiton (length of out is n)
  if(str.size() == 0)
  {
    cout << out << endl;
    return;
  }

  // One be one move all characters at
  // the beginning of out (or result)
  for(int i = 0; i < str.size(); i++)
    {
      // Remove first character from str and add it to out
      permute(str.substr(1), out + str[0]);

      // Rotate string in a way second character moves
      // to the beginning
      rotate(str.begin(), str.begin() +1, str.end());
    }
}

