#ifndef BST_HPP
#define BST_HPP
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

using namespace std;

struct HashNode
{
  int key;
  HashNode *left=NULL;
  HashNode* right=NULL;
};


class HashTable {
private:
  HashNode* table[TABLE_SIZE];
	int h(int k, int functionOption);
  int M;
public:
	HashTable();
  void insert(int k, int functionOption);
  HashNode* search(int k, int functionOption);
  void deleteKey(int k, int functionOption);
	void printTable();
  void insertTimer(vector<int> &dataSet, int functionOption);
  void deleteTimer(vector<int> &dataSet, int functionOption);
  void searchTimer(vector<int> &dataSet, int functionOption);
};

#endif
