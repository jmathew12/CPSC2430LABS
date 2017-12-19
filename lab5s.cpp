// Sasank Kanuri
// lab5.cpp
// 11/17/2017

#include <iostream>
#include <fstream>
using namespace std;

struct Population
{
  int key;
  string place;
};

const string INPUTFILE = "/home/fac/sreeder/class/cs2430/countyPop.dat";
void merge(Population array[], Population temp[], int leftPos, int rightPos,
           int rightEnd);
void mergeSort(Population array[], Population temp[], int first, int last);
void print(Population array[], int count);

int main()
{
  ifstream inputFile;
  Population data[3200];
  Population tempData[3200];
  int count;
  inputFile.open(INPUTFILE);
  if(inputFile.fail()){
    cout <<"Error opening the file...";
  }
  while(inputFile >> data[count].key){
    getline(inputFile, data[count].place);
    count++;
  }
  print(data, count);
  mergeSort(data, tempData, 0, count - 1);
  print(data, count);
}

void mergeSort(Population array[], Population temp[], int first, int last)
{
  if(first < last){
    int center = (first + last)/2;
    mergeSort(array, temp, first, center);
    mergeSort(array, temp, center + 1, last);
    merge(array, temp, first, center + 1, last);
  }
}

void print(Population array[], int count)
{
  cout << "The first 10 entries..." <<endl;
  for(int i = 0; i < 10; i++){
    cout << array[i].key <<" ";
    cout << array[i].place <<endl;
  }
  cout <<"The last 10 entries..." <<endl;
  for(int j = count - 10; j < count; j++){
    cout << array[j].key <<" ";
    cout << array[j].place <<endl;
  }

}    
                             
void merge(Population array[], Population temp[], int leftPos, int rightPos,
           int rightEnd)
{
  int leftEnd = rightPos -1;
  int tempPos = leftPos;
  int numElements = rightEnd - leftPos + 1;

  while(leftPos <= leftEnd && rightPos <= rightEnd){
    if(array[leftPos].key <= array[rightPos].key){
      temp[tempPos] = array[leftPos];
      tempPos++;
      leftPos++;
    }
    else{
      temp[tempPos] = array[rightPos];
      tempPos++;
      rightPos++;
    }
  }
  while(leftPos <= leftEnd){
    temp[tempPos] = array[leftPos];
    tempPos++;
    leftPos++;
  }
  while(rightPos <= rightEnd){
    temp[tempPos] = array[rightPos];
    tempPos++;
    rightPos++;
  }
  for(int i = 0; i < numElements; i++){
    array[rightEnd] = temp[rightEnd];
    rightEnd--;
  }
}