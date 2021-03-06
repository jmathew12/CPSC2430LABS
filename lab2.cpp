// James Mathew
// lab2.cpp

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
  int num;
  int* pnum;

  srand(time(0));
  
  cout << "Num? ";
  cin >> num;

  pnum = &num;

  // print value and address
  cout << "The value of your number is " << num << endl;
  cout << "The address of your number is " << &num << endl;
  cout << "The value of your pointer is " << *pnum << endl;
  cout << "The address of your pointer is " << pnum << endl;
  pnum = new int;
  
  *pnum = 34;

  // print value and address
  cout << "The new value of your pointer is " << *pnum << endl;
  cout << "The new address of your pointer is " << pnum << endl;
  delete pnum;

  cout << "Small number please? ";
  cin >> num;

  pnum = new int[num];

  for (int i = 0; i < num; i++) {
    pnum[i] = rand() % 100;
  }
  
  // print all elemnts in the array
  for (int i = 0; i < num; i++) {
    if (i == 0) {
      cout << "First value in the arry is  " << pnum[i] << endl;
      cout << "The address of your pointer is " << &pnum[i] << endl;
    } else {
      cout << "Next value in the arry is  " << pnum[i] << endl;
      cout << "The address of your pointer is " << &pnum[i] << endl;
    }
  }
  delete (pnum);
  
  return 0;
}
