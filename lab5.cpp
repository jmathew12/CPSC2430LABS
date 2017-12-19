// James Mathew
// lab5.cpp

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct Population
{
  int key;
  string place;
};

void merge(Population set[], Population temp[], int left, int right,
           int rightEnd);
void mergeSort(Population set[], Population temp[], int first, int last);
void print(Population set[], int count);


const int MAX = 3200;
const int PRINT_MAX = 10;
const string INPUTFILE = "/home/fac/sreeder/class/cs2430/countyPop.dat";
// const string INPUTFILE = "lab5.txt";
int main () 
{
  ifstream inputFile;
  Population data[MAX];
  Population tempData[MAX];
  int count = 0;
  
  inputFile.open(INPUTFILE);
  if (inputFile.fail()) {
    cout <<"Error opening the file .." << endl;
  }
  while (inputFile >> data[count].key){
    getline(inputFile, data[count].place);
    count++;
  }
  inputFile.close();
  cout << "Before sorting, ";
  print(data, count);
  mergeSort(data, tempData, 0, count - 1);
  cout << "After sorting, ";
  print(data, count);
  return 0;
}
void mergeSort(Population set[], Population temp[], int first, int last)
{
  if(first < last) {
    int center = (first + last) / 2;
    mergeSort(set, temp, first, center);
    mergeSort(set, temp, center + 1, last);
    merge(set, temp, first, center + 1, last);
  }
}

void merge(Population set[], Population temp[], int left, int right,
           int rightEnd)
{
  int leftEnd = right - 1;
  int tempIndx = left;
  int numElements = rightEnd - left + 1;
  while(left <= leftEnd && right <= rightEnd){
    if(set[left].key <= set[right].key){
      temp[tempIndx] = set[left];
      tempIndx++;
      left++;
    }
    else{
      temp[tempIndx] = set[right];
      tempIndx++;
      right++;
    }
  }
  while(left <= leftEnd){
    temp[tempIndx] = set[left];
    tempIndx++;
    left++;
  }
  while(right <= rightEnd){
    temp[tempIndx] = set[right];
    tempIndx++;
    right++;
  }
  for(int i = 0; i < numElements; i++){
    set[rightEnd] = temp[rightEnd];
    rightEnd--;
  }
}

void print(Population set[], int count)
{
  cout << "the first 10 entries are the following:" << endl;
  for (int i = 0; i < 10; i++) {
    cout << set[i].key << " ";
    cout << set[i].place << endl;
  }
  cout << endl;
  cout << "And the last 10 entries are the following:" << endl;
  for (int i = count - 10; i < count; i++) {
    cout << set[i].key << " ";
    cout << set[i].place << endl;
  }
  cout << endl;
  
}
