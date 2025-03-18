#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
  // initialize an array of 6 elements (from 0 to 7) to zero
  int counts[7] = {0};

  // variables
  int num;
  int rolls;
  int sets;

  // ask
  cout << "How many times do you want to roll?\nPlease be incremental by 5 (Max 20): ";
  cin >> rolls;

  cout << "\nHow many sets do you want to roll? (Max 50): ";
  cin >> sets;

  srand(time(NULL)); // sets seed

  // clear console
  cout << "\033c";

  // set limits
  if (sets > 50) {
    sets = 50;
    cout << "You entered the set number to something greater than 50. It has been set to 50.\n" << endl;
  } else if (sets < 1) {
    sets = 1;
    cout << "You entered the set number to something less than 1. It has been set to 1.\n" << endl;
  }

  // rolls limits
  if (rolls > 20) {
    rolls = 20;
    cout << "You entered the roll number to something greater than 20. It has been set to 20.\n" << endl;
  } else if (rolls < 1) {
    rolls = 1;
    cout << "You entered the roll number to something less than 1. It has been set to 1.\n" << endl;
  }

  cout << "Rolls: " << rolls << endl;
  cout << "Sets: " << sets << endl << endl;

  // loop sets
  for (int j = 1; j <= sets; j++) {
    cout << "Set #" << j << endl;
    cout << "---------------------------" << endl;
    // roll n amount of times
    for (int i = 1; i <= rolls; i++) {
      // pick a number between 1 - 6
      int num = (1 + (rand() % 6));
      cout << num; // comment this out if you only wanna see output

      // increment the count for this number
      counts[num]++;

      // if counter is divisible by 5, begin new line
      if (i % 5 == 0)
        cout << "\n";
      // comment this out if you only wanna see output
      // this goes with "cout << num"
    }
    // output the counts
    cout << endl;
    for (int i = 1; i <= 6; i++)
      cout << "Number " << i << " appeared " << counts[i] << " times.\n";

    // reset counter
    for (int i = 1; i <= 6; i++)
      counts[i] = {0};

    cout << "============================\n" << endl;
  }
  return 0;
}
