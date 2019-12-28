#ifndef LP_HPP
#define LP_HPP

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


class HashTable {
private:
	int M;
	int* table;
	int h(int k, int functionOption);
public:
  vector<int>* dataSet;
	HashTable();
	~HashTable();
  int linearProbe(int k);
	int hash(int k, int functionOption);
  int search(int k, int functionOption);
  void deleteKey(int k, int functionOption);
  void insertTimer(vector<int> &dataSet, int functionOption);
  void deleteTimer(vector<int> &dataSet, int functionOption);
  void searchTimer(vector<int> &dataSet, int functionOption);
  void printVector(vector<int> const &dataSet);
  void printTable();
};

#endif
