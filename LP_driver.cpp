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

void loadFactorMenu(){
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an load factor:" << endl;
  cout << "1. 0.1" << endl;
	cout << "2. 0.2" << endl;
	cout << "3. 0.5" << endl;
  cout << "4. 0.7" << endl;
  cout << "5. 0.9" << endl;
  cout << "6. 1"   << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char* argv[])
{
  string inputName=argv[1];
  ifstream inStream;
  inStream.open(inputName);

  int option=0;
	int functionOption;

  string sKey;
  int x;
  int count=0;
  string line;
  vector<int> dataSet;
  int i=0;


	HashTable myTable;

//creates vector from csv dataSet
  if(inStream.is_open())
  {
    while(getline(inStream, sKey, ','))
    {
        getline(inStream, sKey, ',');
        x=stoi(sKey);
        dataSet.push_back(x);
      }
  }

  auto rng=std::default_random_engine{};
  std::shuffle(std::begin(dataSet), std::end(dataSet), rng);

  ////shuffles before each function
  // while (option==0){
	// cout << "Please choose a hash function:" << endl;
  // cout << "1. h(x)=x % tablesize" << endl;
  // cout << "2. h'(x) = (x/tablesize) % tablesize" << endl;
  // cin >> functionOption;
  // loadFactorMenu();
  // cin >> option;
  //   if (option==1){
  //     //loadFactor 0.1:
  //     cout << "Load factor 0.1 times: " << endl;
  //     for (int i=0; i<1000; i++){
  //       myTable.hash(dataSet[i], functionOption);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet, functionOption);
  //   }
  //   if (option==2){
  //     cout << "Load factor 0.2 times: " << endl;
  //     for (int i=0; i<2001; i++){
  //       myTable.hash(dataSet[i], functionOption);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet, functionOption);
  //   }
  //   if (option==3){
  //     cout << "Load factor 0.5 times: " << endl;
  //     for (int i=0; i<5004; i++){
  //       myTable.hash(dataSet[i], functionOption);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet, functionOption);
  //   }
  //   if (option==4){
  //     cout << "Load factor 0.7 times: " << endl;
  //     for (int i=0; i<7006; i++){
  //       myTable.hash(dataSet[i], functionOption);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet, functionOption);
  //   }
  //   if (option==5){
  //     cout << "Load factor 0.9 times: " << endl;
  //     for (int i=0; i<9008; i++){
  //       myTable.hash(dataSet[i], functionOption);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet, functionOption);
  //   }
  //   if (option==6){
  //     cout << "Load factor 1 times: " << endl;
  //     for (int i=0; i<10009; i++){
  //       myTable.hash(dataSet[i], functionOption);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet, functionOption);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet, functionOption);
  //   }
  // }

  //shuffles before delete and insert functions
	while (option==0){
		cout << "Please choose a hash function:" << endl;
		cout << "1. h(x)=x % tablesize" << endl;
		cout << "2. h'(x) = (x/tablesize) % tablesize" << endl;
		cin >> functionOption;
		loadFactorMenu();
		cin >> option;
    if (option==1){
      //loadFactor 0.1:
      cout << "Load factor 0.1 times: " << endl;
      for (int i=0; i<1000; i++){
        myTable.hash(dataSet[i], functionOption);
      }
			// myTable.printTable();
			myTable.deleteTimer(dataSet,functionOption);
			std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
      myTable.insertTimer(dataSet, functionOption);
      myTable.searchTimer(dataSet, functionOption);
    }
    if (option==2){
      cout << "Load factor 0.2 times: " << endl;
      for (int i=0; i<2001; i++){
        myTable.hash(dataSet[i], functionOption);
      }
			// myTable.printTable();
      myTable.deleteTimer(dataSet, functionOption);
			std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
      myTable.insertTimer(dataSet, functionOption);
      myTable.searchTimer(dataSet, functionOption);
    }
    if (option==3){
      cout << "Load factor 0.5 times: " << endl;
      for (int i=0; i<5004; i++){
        myTable.hash(dataSet[i], functionOption);
      }
			// myTable.printTable();
      myTable.deleteTimer(dataSet, functionOption);
			std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
      myTable.insertTimer(dataSet, functionOption);
      myTable.searchTimer(dataSet, functionOption);
    }
    if (option==4){
      cout << "Load factor 0.7 times: " << endl;
      for (int i=0; i<7006; i++){
        myTable.hash(dataSet[i], functionOption);
      }
			// myTable.printTable();
			myTable.deleteTimer(dataSet, functionOption);
			std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
      myTable.insertTimer(dataSet, functionOption);
      myTable.searchTimer(dataSet, functionOption);
    }
    if (option==5){
      cout << "Load factor 0.9 times: " << endl;
      for (int i=0; i<9008; i++){
        myTable.hash(dataSet[i], functionOption);
      }
			// myTable.printTable();
			myTable.deleteTimer(dataSet, functionOption);
			std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
      myTable.insertTimer(dataSet, functionOption);
      myTable.searchTimer(dataSet, functionOption);
    }
    if (option==6){
      cout << "Load factor 1 times: " << endl;
      for (int i=0; i<10009; i++){
        myTable.hash(dataSet[i], functionOption);
      }
			// myTable.printTable();
			myTable.deleteTimer(dataSet, functionOption);
			std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
      myTable.insertTimer(dataSet, functionOption);
      myTable.searchTimer(dataSet, functionOption);
    }
  }
	// myTable.printTable();
  inStream.close();

	return 0;
}
