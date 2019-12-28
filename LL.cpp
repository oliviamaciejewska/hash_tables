#include "LL.hpp"
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
#define TABLE_SIZE 10009

HashTable::HashTable()
{
  M=10009;
  for (int i=0; i<M; i++)
		table[i] = NULL;
}

HashTable::~HashTable()
{
  HashNode* crawler;
  for (int i=0; i<10009; i++)
  {
    while(table[i] != NULL)
    {
      crawler=table[i]->next;
      delete table[i];
      table[i]=crawler;
    }
  }

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

void HashTable::insert(int k, int functionOption)
{
  HashNode* temp= new HashNode;
  temp->key=k;
  temp->next=NULL;

  int indexInsert=h(k, functionOption);
  HashNode* ptr=table[indexInsert];

  if (table[indexInsert]==NULL)
  {
    table[indexInsert]=temp;
  }
  else
  {
    while(ptr->next != NULL)
    {
      ptr=ptr->next;
    }
    ptr->next=temp;
  }
}

HashNode* HashTable::search(int k, int functionOption)
{
  int indexSearch=h(k, functionOption);
  if(table[indexSearch]==NULL)
  {
    return NULL;
  }
  else
  {
    HashNode* temp=table[indexSearch];
    while(temp != NULL && temp->key != k)
    {
      temp=temp->next;
    }
    if (temp==NULL)
    {
      return NULL;
    }
    else
    {
      return temp;
    }
  }
}

void HashTable::deleteKey(int k, int functionOption)
{
  int deleteIndex=h(k, functionOption);
  HashNode* deletePtr=table[deleteIndex];
  while (deletePtr != NULL && deletePtr->key !=k)
  {
    deletePtr=deletePtr->next;
  }
  if (deletePtr != NULL)
  {
    if (deletePtr==table[deleteIndex])
    {
      table[deleteIndex]=table[deleteIndex]->next;
      delete deletePtr;
    }
    else
    {
      HashNode* previous=table[deleteIndex];
      while (previous->next != deletePtr)
      {
        previous=previous->next;
      }
      previous->next=previous->next->next;
      delete deletePtr;
    }
  }
}

void HashTable::insertTimer(vector<int> &dataSet, int functionOption){
  LARGE_INTEGER frequency;
  LARGE_INTEGER startTime, endTime, totalTime;

  QueryPerformanceFrequency(&frequency);
  QueryPerformanceCounter(&startTime);

  for(int i=0; i<100; i++)
  {
    insert(dataSet[i], functionOption);
  }
  QueryPerformanceCounter(&endTime);
    totalTime.QuadPart = ((endTime.QuadPart - startTime.QuadPart) * 1e9) / frequency.QuadPart;
    //1e9 is nanoseconds, 1e6 microseconds, 1e3 is milliseconds
    //the multiplier is what changes the form of measurement, which are listed above.

    cout << "Insert time: " << totalTime.QuadPart << " nanoseconds for 100 inserts" << endl;
}

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

void HashTable::printTable()
{
  ofstream outStream;
  outStream.open("LL.csv");
  for (int i=0; i<10009; i++)
  {
    HashNode* crawler=table[i];
    while(crawler !=NULL)
    {
      outStream << crawler->key << ",";
      crawler=crawler->next;
    }
    // if(table[i] != NULL)
    // {
    //   outStream << "NULL" << endl;
    // }
    if (table[i]==NULL)
    {
      outStream << "-1" << endl;
    }
  }
}
