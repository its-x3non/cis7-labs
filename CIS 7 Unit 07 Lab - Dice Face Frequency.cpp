#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  // frequency counter
  int freq1 = 0;
  int freq2 = 0;
  int freq3 = 0;
  int freq4 = 0;
  int freq5 = 0;
  int freq6 = 0;

  // roll and face variables
  int roll;
  int face;

  // start for
  for (roll = 1; roll <= /* 6000 */ /* 100 */ 1000; roll++){
    // random num from 1-6
    face = 1 + rand() % 6;

    // determine face value and increment appropriately
    switch(face){
      case 1:
        ++freq1;
        break;
      case 2:
        ++freq2;
        break;
      case 3:
        ++freq3;
        break;
      case 4:
        ++freq4;
        break;
      case 5:
        ++freq5;
        break;
      case 6:
        ++freq6;
        break; // Without the breaks, freq would be different
    }
  } // end for

  // display freq
  cout << "\n" << "Face   |" << "Frequency";
  cout << "\n" << "Face 1 |" << (freq1);
  cout << "\n" << "Face 2 |" << (freq2); 
  cout << "\n" << "Face 3 |" << (freq3); 
  cout << "\n" << "Face 4 |" << (freq4); 
  cout << "\n" << "Face 5 |" << (freq5); 
  cout << "\n" << "Face 6 |" << (freq6);
  return 0;
}
