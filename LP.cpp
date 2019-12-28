#include "LP.hpp"
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

//default constructor- initializes table to -1 for all indecies
HashTable::HashTable() {
	M = 10009;
	table = new int[M];
	for (int i=0; i<M; i++)
		table[i] = -1;
}

//default destructor
HashTable::~HashTable()
{
	delete[] table;
}

//hash function option
int HashTable::h(int k, int functionOption) {
	switch(functionOption)
	{
		case 1:
			return (k % M);
			break;
		case 2:
		 	return (k/M) % M;
			break;
	}
}

//linear probe function to find next available position
int HashTable::linearProbe(int k) {
	for (int i=k+1; i!=k; i++) {
		if (i>=M) { // wrap around
			i = -1;
			continue;
		}
		if (table[i] == -1) return i;
	}

  //returns -1 if no available positions
	return -1;
}

//function to insert
int HashTable::hash(int k, int functionOption) {
	int index = h(k, functionOption);
	if (table[index] >= 0)
		index = linearProbe(index);
	if (index >= 0)
    table[index] = k;
	else{
		// returns -1 if there are no available buckets (if linearProbe() returns -1)
		return -1;
	}
}

//searches for index of given key
//returns index of key if found, if not returns -1
int HashTable::search(int k, int functionOption){
  int searchIndex = h(k, functionOption);
  if (table[searchIndex] == k)
	{
		return searchIndex;
	}
	else
	{
		for (int i=searchIndex+1; i!=searchIndex; i++) {
			if (i>=M) { // wrap around
				i = -1;
				continue;
			}
			if (table[i] == k)
			{
				return i;
			}
		}
	}
	return -1;
}

//deletes key if found
void HashTable::deleteKey(int k, int functionOption){
  int deleteIndex=search(k, functionOption);
  if(deleteIndex >= 0)
  {
    table[deleteIndex]=-1;
  }
}

//function to time 100 inserts
void HashTable::insertTimer(vector<int> &dataSet, int functionOption){
  LARGE_INTEGER frequency;
  LARGE_INTEGER startTime, endTime, totalTime;
  // auto startTime= chrono::high_resolution_clock::now();

  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&startTime);

  for(int i=0; i<100; i++)
  {
    hash(dataSet[i], functionOption);
  }
  QueryPerformanceCounter(&endTime);
    totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e9) / frequency.QuadPart;
    //1e9 is nanoseconds, 1e6 microseconds, 1e3 is milliseconds
    //the multiplier is what changes the form of measurement, which are listed above.

    cout << "Insert time: " << totalTime.QuadPart << " nanoseconds for 100 inserts" << endl;
}

//function to time 100 deletes
void HashTable::deleteTimer(vector<int> &dataSet, int functionOption){
  LARGE_INTEGER frequency;
  LARGE_INTEGER startTime, endTime, totalTime;
  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&startTime);

  for(int i=0; i<100; i++)
  {
    deleteKey(dataSet[i], functionOption);
  }
  QueryPerformanceCounter(&endTime);
    totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e9) / frequency.QuadPart;
    //1e9 is nanoseconds, 1e6 microseconds, 1e3 is milliseconds
    cout << "Delete time: " << totalTime.QuadPart << " nanoseconds for 100 deletes" << endl;
}

//function to time 100 searches
void HashTable::searchTimer(vector<int> &dataSet, int functionOption){
  LARGE_INTEGER frequency;
  LARGE_INTEGER startTime, endTime, totalTime;
  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&startTime);

  for(int i=0; i<100; i++)
  {
    search(dataSet[i], functionOption);
  }
  QueryPerformanceCounter(&endTime);
    totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e9) / frequency.QuadPart;
    //1e9 is nanoseconds, 1e6 microseconds, 1e3 is milliseconds
    cout << "Search time: " << totalTime.QuadPart << " nanoseconds for 100 searches" << endl;
}

//for testing purposes prints data set vector that was made from the csv file
void HashTable::printVector(vector<int> const &dataSet)
{
  for (auto it=dataSet.cbegin(); it != dataSet.cend(); it++)
  {
    cout << *it << ',';
  }
}

//for data and testing purposes prints hash table to csv file
void HashTable::printTable() {
	ofstream outStream;
	outStream.open("LP-1A-2.csv");
	for (int i=0; i<M; i++)
		outStream << table[i] << endl;
}
