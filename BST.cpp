#include "BST.hpp"
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

// HashNode* createNode(int k)
// {
//   HashNode* temp= new HashNode;
//   temp->key=k;
//   temp->left=NULL;
//   temp->right=NULL;
//   return temp;
//
// }
// HashNode* insertHelper(HashNode* r, int k)
// {
//   if (r==NULL)
//   {
//     r=createNode(k);
//   }
//   else
//   {
//     if(r->key <= k)
//     {
//       r->right=insertHelper(r->right, k);
//     }
//     else
//     {
//       r->left=insertHelper(r->left, k);
//     }
//   }
//   return r;
// }
// void HashTable::insert(int k, int functionOption)
// {
//   int indexInsert=h(k, functionOption);
//   HashNode* root=table[indexInsert];
//   root=insertHelper(root, k);
//   table[indexInsert]=root;
// }

HashNode* insertHelper(HashNode* r, HashNode* temp)
{
  if (r==NULL)
  {
    r=temp;
  }
  else
  {
    if(r->key <= temp->key)
    {
      r->right=insertHelper(r->right, temp);
    }
    else
    {
      r->left=insertHelper(r->left, temp);
    }
  }
}
void HashTable::insert(int k, int functionOption)
{
  HashNode* temp= new HashNode;
  temp->key=k;
  temp->left=NULL;
  temp->right=NULL;

  int indexInsert=h(k, functionOption);
  HashNode* ptr=table[indexInsert];

  if (table[indexInsert]==NULL)
  {
    table[indexInsert]=temp;
  }
  else
  {
    insertHelper(ptr, temp);
  }
}

HashNode* searchHelper(HashNode* crawler, int k)
{
  if(crawler)
  {
    if(crawler->key==k)
    {
      return crawler;
    }
    else if(crawler->key < k)
    {
      searchHelper(crawler->right, k);
    }
    else if(crawler->key > k)
    {
      searchHelper(crawler->left, k);
    }
  }
  else return NULL;
}

HashNode* HashTable::search(int k, int functionOption)
{
  int indexSearch=h(k, functionOption);
  HashNode* root=table[indexSearch];
  if(root==NULL)
  {
    return NULL;
  }
  else
  {
    return searchHelper(root, k);
  }
}

HashNode* minValueNode(HashNode* node)
{
  HashNode* current=node;
  while(current && current->left !=NULL)
  {
    current=current->left;
  }
  return current;
}

HashNode* deleteKeyHelper(HashNode* r, int k)
{
  if (r==NULL)
  {
    return NULL;
  }
  if (r->key > k)
  {
    r->left=deleteKeyHelper(r->left, k);
  }
  else if(r->key < k)
  {
    r->right=deleteKeyHelper(r->right, k);
  }
  else
  {
    if (r->left==NULL)
    {
      HashNode* temp= r->right;
      free(r);
      return temp;
    }
    else if(r->right==NULL)
    {
      HashNode* temp= r->left;
      free(r);
      return temp;
    }
    HashNode* temp=minValueNode(r->right);
    r->key=temp->key;
    r->right=deleteKeyHelper(r->right, temp->key);
  }
  return r;
}

void HashTable::deleteKey(int k, int functionOption)
{
  int deleteIndex=h(k, functionOption);
  HashNode* root= table[deleteIndex];
  deleteKeyHelper(root, k);
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
    cout << "Insert time: " << totalTime.QuadPart << " nanoseconds for 100 inserts"<< endl;
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
    cout << "Delete time: " << totalTime.QuadPart << " nanoseconds for 100 deletes"<< endl;
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
    cout << "Search time: " << totalTime.QuadPart << " nanoseconds for 100 searches"<< endl;
}


void printHelper(HashNode* t, ofstream& outStream)
{
  if (t!=NULL)
  {
    printHelper(t->left, outStream);

    outStream << t->key << ",";

    printHelper(t->right, outStream);
  }
  else
  {
    outStream << "-1" << endl;
  }
}


void HashTable::printTable()
{
  ofstream outStream;
  outStream.open("BST.csv");
  HashNode *t;
  for (int i=0; i<10009; i++)
  {
    t=table[i];
    printHelper(t, outStream);
  }
  outStream.close();
}
