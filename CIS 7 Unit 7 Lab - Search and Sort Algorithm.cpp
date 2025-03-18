#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
using namespace std;

// Global Variables
int option;

// Utility Functions
char goAgain();
void printArray(int arr[], int size);
void beforeAfter(int arr[], int size);

// Binary Search
int binarySearch(int arr[], int l, int r, int x);
void binaryExamples();

// Jump Search
int jumpSearch(int arr[], int x, int n);
void example3();

// Quick Sort using sort() STL
void example4();

// Selection Sort
void selectionSort(int arr[], int n);
void example5();

// Merge Sort
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void example6();

// Main Function
int main() {
  char again = 'Y';

  while (again == 'y' || again == 'Y') {
    cout << "\033c";

    // list
    cout << "Unit 7 Lab - Searches and Sorts" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1) Binary Search: Iterative Implementation" << endl;
    cout << "2) Binary Search: Recursive Implementation" << endl;
    cout << "3) Jump Search" << endl;
    cout << "4) Quick Sort using sort() STL" << endl;
    cout << "5) Selection Sort" << endl;
    cout << "6) Merge Sort" << endl;
    cout << "7) Quit Program" << endl;
    cout << "\nType in which example to view\n(1-6, 7 to Quit): #";

    // Option Reset
    while (!(cin >> option)) {
      cout << "\nPlease type a valid option" << endl;
      cout << "Type in which example to view\n(1-6, 7 to Quit): #";
      cin.clear();
      cin.ignore(100, '\n');
    }

    // Switch Cases
    switch (option) {
    case 1:            // Binary Search - Iterative
      cout << "\033c"; // This clears the console (at least on replit)

      // Title
      cout << "Example 1) Binary Search: Iterative Implementation" << endl;
      cout << "----------------------------------------------------" << endl;
      binaryExamples();
      cout << endl;
      again = goAgain();
      break;
    case 2: // Binary Search - Recursive
      cout << "\033c";

      // Title
      cout << "Example 2) Binary Search: Recursive Implementation" << endl;
      cout << "----------------------------------------------------" << endl;

      binaryExamples();
      cout << endl;
      again = goAgain();
      break;
    case 3: // Jump Search
      cout << "\033c";

      // Title
      cout << "Example 3) Jump Search" << endl;
      cout << "--------------------------------------" << endl;

      example3();
      cout << endl;
      again = goAgain();
      break;
    case 4: // Quick Sort using sort() STL
      cout << "\033c";

      // Title
      cout << "Example 4) Quick Sort using sort() STL" << endl;
      cout << "--------------------------------------" << endl;

      example4();
      cout << endl;
      again = goAgain();
      break;
    case 5: // Selection Sort
      cout << "\033c";

      // Title
      cout << "Example 5) Selection Sort" << endl;
      cout << "--------------------------------------" << endl;

      example5();
      cout << endl;
      again = goAgain();
      break;
    case 6: // Merge Sort
      cout << "\033c";

      // Title
      cout << "Example 6) Merge Sort" << endl;
      cout << "--------------------------------------" << endl;

      example6();
      cout << endl;
      again = goAgain();
      break;
    case 7:
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

// Function to print an array
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
}

// Function to display before & after
void beforeAfter(int arr[], int size) {
  // Before
  cout << "Array before sorting: " << endl;
  printArray(arr, size);

  // Sort
  if (option == 4)
    sort(arr, arr + size);
  else if (option == 5)
    selectionSort(arr, size);
  else if (option == 6)
    mergeSort(arr, 0, size - 1);

  // After
  cout << "\nArray after sorting: " << endl;
  printArray(arr, size);
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int x) {

  if (option == 1) {
    // uncomment if need testing
    // cout << "CASE 1 (ITERATIVE)" << endl;
    while (l <= r) {
      int m = l + (r - l) / 2;

      // Check if x is present at mid
      if (arr[m] == x)
        return m;

      // If x greater, ignore left half
      if (arr[m] < x)
        l = m + 1;

      // If x is smaller, ignore right half
      else
        r = m - 1;
    }

    // If we reach here, then element was not present
    return -1;
  }

  if (option == 2) {
    // uncomment if need testing
    // cout << "CASE 2 (RECURSIVE)" << endl;
    if (r >= l) {
      int mid = l + (r - l) / 2;

      // If the element is present at the middle
      // itself
      if (arr[mid] == x)
        return mid;

      // If element is smaller than mid, then
      // it can only be present in left subarray
      if (arr[mid] > x)
        return binarySearch(arr, l, mid - 1, x);

      // Else the element can only be present
      // in right subarray
      return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
  }
}

void binaryExamples() {
  int arr[] = {2, 3, 4, 10, 40};
  int x = 10;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, 0, n - 1, x);

  // Display Array
  printArray(arr, n);

  // Results
  (result == -1) ? cout << "\nElement is not present in array"
                 : cout << "\nElement is present at index " << result;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

int jumpSearch(int arr[], int x, int n) {
  // Finding block size to be jumped
  int step = sqrt(n);

  // Finding the block where element is
  // present (if it is present)
  int prev = 0;
  while (arr[min(step, n) - 1] < x) {
    prev = step;
    step += sqrt(n);
    if (prev >= n)
      return -1;
  }

  // Doing a linear search for x in block
  // beginning with prev.
  while (arr[prev] < x) {
    prev++;

    // If we reached next block or end of
    // array, element is not present.
    if (prev == min(step, n))
      return -1;
  }
  // If element is found
  if (arr[prev] == x)
    return prev;

  return -1;
}

void example3() {
  int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
  int x = 55;
  int n = sizeof(arr) / sizeof(arr[0]);

  // Find the index of 'x' using Jump Search
  int index = jumpSearch(arr, x, n);

  // Display Array
  printArray(arr, n);

  // Print the index where 'x' is located
  cout << "\nNumber " << x << " is at index " << index;
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// QuickSort function
void example4() {
  int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Display
  beforeAfter(arr, n);
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Function for Selection sort
void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  // One by one move boundary of
  // unsorted subarray
  for (i = 0; i < n - 1; i++) {

    // Find the minimum element in
    // unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx])
        min_idx = j;
    }

    // Swap the found minimum element
    // with the first element
    if (min_idx != i)
      swap(arr[min_idx], arr[i]);
  }
}

void example5() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Display
  beforeAfter(arr, n);
}

//////////////////////////////
//////////////////////////////
//////////////////////////////

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  /* create temp arrays */
  int L[n1], R[n2];

  /* Copy data to temp arrays L[] and R[] */
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];

  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  /* Merge the temp arrays back into arr[l..r]*/
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of L[], if there
     are any */
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of R[], if there
     are any */
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Same as (l+r)/2, but avoids overflow for
    // large l and h
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void example6() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Display
  beforeAfter(arr, n);
}