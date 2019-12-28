#ifndef CUCKOO_HPP
#define CUCKOO_HPP
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

class HashTable {
private:
	int M=10009;
	int* table1;
  int* table2;
	int h1(int k);
  int h2(int k);
public:
	HashTable();
  void rehash();
  int insert(int k);
  int insertHelper(int k, int initialK, int index, int count);
  bool isPrime(int N);
  int nextPrime(int n);
	void printTable();
  void insertTimer(vector<int> &dataSet);
  int search(int k);
  void deleteKey(int k);
  void deleteTimer(vector<int> &dataSet);
  void searchTimer(vector<int> &dataSet);
};
#endif
