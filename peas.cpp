// James Mathew
// peas.cpp
// Purpose: This is a sample program that will print the
//  number of peas in a given number of pods.
// Imput: number of pods, number of peas
// Process: simple multiplication
// Outpout: result of multiplying provided numbers
// Example: number of pods: 2, number of peas: 6, result: 12

#include <iostream>
using namespace std;
int main() {
  int peas = 0, pods = 0, totalPeas = 0;
  // explanation
  cout << endl << endl << endl;
  cout << "This will calculate the total number of peas in the pods.";
  cout << endl << endl;

  //input
  cout << "How many pods? ";
  cin >> pods;
  cout << "How many peas in each pod? ";
  cin >> peas;
  // calculation
  totalPeas = pods * peas;

  // oupot
  cout << endl << endl;
  cout << "If you have " << pods << " pods each containing " << endl;
  cout << peas << " peas then you have a total of " << totalPeas
       << " peas." <<endl;
    cout << endl << endl << endl;
  return 0;
}
