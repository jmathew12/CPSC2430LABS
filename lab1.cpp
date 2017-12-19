// James Mathew

#include <iostream>
using namespace std;
int main() {
  cout << "This is lab 1! Welcome to lab 1!" << endl;
  //  int thirteenOdds[13];
  int numberEnt;
  for (int i = 0; i < 13;) {
    cout << "Enter an odd number. " ;
    cin >> numberEnt;
    if (numberEnt % 2 != 0) {
      //      thirteenOdds(i,numberEnt);
      i++;
    } else {
      cout << "You entered an even number!";
      
    }
  }
  cout << endl << "End of Lab 1 Pgm" << endl;
  return 0;
}
