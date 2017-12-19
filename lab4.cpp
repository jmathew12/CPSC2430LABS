//James Mathew
//lab4.cpp
#include <iostream>
using namespace std;
#include <exception>
bool insert(int h[], int value, int& size);
int remove(int h[], int& size);
void percolateDown(int h[], int hole, int size);
const int MAXSIZE = 25;
int main()
{
	int h[MAXSIZE];
	int size = 0;
	cout << endl << endl;
	cout << "tetsing heap by adding values";
	srand(time(0));	
	int val; 
	// int allVals[MAXSIZE];
for (int i = 0; i < MAXSIZE + 5; i++) {
	val = rand() % 100;
	if (insert(h, val, size)) {
		cout << "sucessful add of " << val << endl;
		// allVals[i] = val; // may not need it;
	} else {
		cout<<"not able to add " <<  val << endl;
	}
}
	cout << "size of the heap is: " << size << endl;
	
	cout << "heap contents: ";
	for (int i = 1; i < size; i++) {
		cout << h[i] << " ";
	}	
	cout << endl;
	for (int i = 1; i <= MAXSIZE + 5; i++) {
		cout << remove(h, size) << " ";
		if (i % 5 == 0) {
			cout << endl;
		}
	}
	
	cout << endl;
	return 0;
}

bool insert(int h[], int value, int& size)
{
	if (size == MAXSIZE) {
		return false;
	}
	int hole = size + 1;
	while (hole > 1 && value < h[hole/2]) {
		h[hole] = h[hole/2];
		hole = hole/2;
	}
	h[hole] = value;
	size++;
	return true;
}
int remove(int h[], int& size)
{
	if (size == 0) {
		//throw cout << ("there is nothing left to remove.") ;
		return false;
	}
	int x = h[1];
	h[1] = h[size];
	size--;
	percolateDown(h, 1, size);
	return x;
}

void percolateDown(int h[], int hole, int size) 
{
	int temp = h[hole];
	while ((hole*2 <= size && temp > h[hole*2]) || (hole*2+1 <= size && temp > h[hole*2+1])) {
		if (hole*2+1 <= size && h[hole*2+1] < h[hole*2]) {
			h[hole] = h[hole*2+1];
			hole = hole*2+1;
		} else {
			h[hole] = h[hole*2];
			hole = hole*2;
		}
	}
	h[hole] = temp;
}
