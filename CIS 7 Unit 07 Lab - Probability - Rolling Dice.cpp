#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  // initialize an array of 9 elements (from 0 to 8) to zero
  int counts[9] = {0}; 
  
  for(int i = 1; i <=  90; i++){
    // pick a random number from 1 - 6 and output it
    int num = 1 + (rand() % /* 6 */ 8);
    cout << num;

    // increment the count for this number
    counts[num]++;

    // if counter is divisible by 5, begin a new line
    if(i % 5 == 0)
      cout << ("\n");
  }

  // output the counts
  cout << endl;
  for(int i = 1; i <= /*6*/ 8; i++)
    cout << "Number " << i << " appeared " << counts[i] << " times.\n";

  return 0;
}
