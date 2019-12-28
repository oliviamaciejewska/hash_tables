#include "CUCKOO.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <windows.h>
#include <iomanip>
#include <algorithm>
#include <random>

using namespace std;

HashTable::HashTable() {
	// M = 10009;
	table1 = new int[M];
  table2 = new int[M];
	for (int i=0; i<M; i++)
	{
    table1[i] = -1;
    table2[i] = -1;
  }
}

void HashTable::rehash()
{
  int tempSize=M;
  int newSize= nextPrime(M);
  M=newSize;
  int *tempTable1= new int[M];
  int *tempTable2= new int[M];


  for (int i=0; i<tempSize; i++)
  {
    tempTable1[i]=table1[i];
    tempTable2[i]=table2[i];
  }

  delete[] table1;
  delete[] table2;
  // HashTable();

  // for (int i=0; i<M; i++)
  // {
  //   if(tempTable1[i] != -1)
  //     { int key=tempTable1[i];
  //       insert(key);
  //     }
  // }
  // for (int i=0; i<M;i++)
  // {
  //   if(tempTable2[i] != -1)
  //     {
  //       insert(tempTable2[i]);
  //     }
  // }
  table1=tempTable1;
  table2=tempTable2;
  // delete[] tempTable1;
  // delete[] tempTable2;
}

int HashTable::h1(int k) {
	return k % M;
}

int HashTable::h2(int k) {
  return (k/M) % M;
}

bool HashTable::isPrime(int N)
{
  if (N%2==0 || N%3==0)
  {
    return false;
  }
  for (int i=5; i*i<=N; i=i+6)
  {
    if (N%i==0 || N%(i+2)==0)
      return false;
  }
  return true;
}

int HashTable::nextPrime(int n)
{
  int prime=n;
  bool found=false;
  while(!found){
    prime++;
    if (isPrime(prime))
    {
      found=true;
    }
  }
  return prime;
}

int HashTable::insertHelper(int k, int initialK, int index, int count)
{
  int temp=table1[index];
  if (temp==initialK)
  {
    rehash();
    cout << "rehash" << endl;
  }
  int altIndex=h2(table1[index]);
  table1[index]=k;
  if (table2[altIndex]==-1)
  {
    table2[altIndex]=temp;
    return k;
  }
  else
  {
    insertHelper(temp, initialK, altIndex, count +1);
  }
}

int HashTable::insert(int k)
{
  int indexInsert=h1(k);
  if (table1[indexInsert]==-1)
  {
    table1[indexInsert]=k;
    return k;
  }
  int indexInsert2=h2(k);
  if(table2[indexInsert2]==-1)
  {
    table2[indexInsert2]=k;
    return k;
  }
  else
  {
    int count=0;
    insertHelper(k, k, indexInsert, count);
  }
}

int HashTable::search(int k)
{
  int index1=h1(k);
  if (table1[index1]==k)
  {
    return table1[index1];
  }
  else
  {
    int index2=h2(k);
    if(table2[index2]==k);
    return table2[index2];
  }
  return -1;
}

void HashTable::deleteKey(int k)
{
  int index1=h1(k);
  if(table1[index1]==k)
  {
    table1[index1]=-1;
  }
  else
  {
    int index2=h2(k);
    if (table2[index2]==k)
    {
      table2[index2]=-1;
    }
  }
}

void HashTable::printTable() {
	ofstream outStream;
	outStream.open("cuckooA3.csv");
	for (int i=0; i<M; i++)
		outStream << table1[i] << ',' << table2[i] << endl;
}

void HashTable::insertTimer(vector<int> &dataSet){
  LARGE_INTEGER frequency;
  LARGE_INTEGER startTime, endTime, totalTime;
  // auto startTime= chrono::high_resolution_clock::now();

  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&startTime);

  for(int i=0; i<100; i++)
  {
    insert(dataSet[i]);
  }
  QueryPerformanceCounter(&endTime);
    totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e9) / frequency.QuadPart;
    //1e9 is nanoseconds, 1e6 microseconds, 1e3 is milliseconds
    cout << "Insert time: " << totalTime.QuadPart << endl;
}


void HashTable::deleteTimer(vector<int> &dataSet){
  LARGE_INTEGER frequency;
  LARGE_INTEGER startTime, endTime, totalTime;
  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&startTime);

  for(int i=0; i<100; i++)
  {
    deleteKey(dataSet[i]);
  }
  QueryPerformanceCounter(&endTime);
    totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e9) / frequency.QuadPart;
    //1e9 is nanoseconds, 1e6 microseconds, 1e3 is milliseconds
    cout << "Delete time: " << totalTime.QuadPart << endl;
}

void HashTable::searchTimer(vector<int> &dataSet){
  LARGE_INTEGER frequency;
  LARGE_INTEGER startTime, endTime, totalTime;
  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&startTime);

  for(int i=0; i<100; i++)
  {
    search(dataSet[i]);
  }
  QueryPerformanceCounter(&endTime);
    totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e9) / frequency.QuadPart;
    //1e9 is nanoseconds, 1e6 microseconds, 1e3 is milliseconds
    cout << "Search time: " << totalTime.QuadPart << endl;
}
