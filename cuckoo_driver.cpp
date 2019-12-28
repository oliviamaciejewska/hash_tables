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

  string sKey;
  int x;
  int count=0;
  string line;
  vector<int> dataSet;
  int i=0;

	HashTable myTable;

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
  // while (option==0){
  //   loadFactorMenu();
  //   cin >> option;
  //   if (option==1){
  //     //loadFactor 0.1:
  //     cout << "Load factor 0.1 times: " << endl;
  //     for (int i=0; i<1000; i++){
  //       myTable.hash(dataSet[i]);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet);
  //   }
  //   if (option==2){
  //     cout << "Load factor 0.2 times: " << endl;
  //     for (int i=0; i<2001; i++){
  //       myTable.hash(dataSet[i]);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet);
  //   }
  //   if (option==3){
  //     cout << "Load factor 0.5 times: " << endl;
  //     for (int i=0; i<5004; i++){
  //       myTable.hash(dataSet[i]);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet);
  //   }
  //   if (option==4){
  //     cout << "Load factor 0.7 times: " << endl;
  //     for (int i=0; i<7006; i++){
  //       myTable.hash(dataSet[i]);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet);
  //   }
  //   if (option==5){
  //     cout << "Load factor 0.9 times: " << endl;
  //     for (int i=0; i<9008; i++){
  //       myTable.hash(dataSet[i]);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet);
  //   }
  //   if (option==6){
  //     cout << "Load factor 1 times: " << endl;
  //     for (int i=0; i<10009; i++){
  //       myTable.hash(dataSet[i]);
  //     }
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.deleteTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.insertTimer(dataSet);
  //     std::shuffle(std::begin(dataSet), std::end(dataSet), rng);
  //     myTable.searchTimer(dataSet);
  //   }
  // }
	while (option==0){
    loadFactorMenu();
    cin >> option;
    if (option==1){
      //loadFactor 0.1:
      cout << "Load factor 0.1 times: " << endl;
      for (int i=0; i<1000; i++){
        myTable.insert(dataSet[i]);
      }
			// myTable.printTable();
			myTable.deleteTimer(dataSet);
      myTable.insertTimer(dataSet);
      myTable.searchTimer(dataSet);
    }
    if (option==2){
      cout << "Load factor 0.2 times: " << endl;
      for (int i=0; i<2001; i++){
        myTable.insert(dataSet[i]);
      }
			// myTable.printTable();
      myTable.deleteTimer(dataSet);
      myTable.insertTimer(dataSet);
      myTable.searchTimer(dataSet);
    }
    if (option==3){
      cout << "Load factor 0.5 times: " << endl;
      for (int i=0; i<5004; i++){
        myTable.insert(dataSet[i]);
      }
			// myTable.printTable();
      myTable.deleteTimer(dataSet);
      myTable.insertTimer(dataSet);
      myTable.searchTimer(dataSet);
    }
    if (option==4){
      cout << "Load factor 0.7 times: " << endl;
      for (int i=0; i<7006; i++){
        myTable.insert(dataSet[i]);
      }
			// myTable.printTable();
			myTable.deleteTimer(dataSet);
      myTable.insertTimer(dataSet);
      myTable.searchTimer(dataSet);
    }
    if (option==5){
      cout << "Load factor 0.9 times: " << endl;
      for (int i=0; i<9008; i++){
        myTable.insert(dataSet[i]);
      }
			// myTable.printTable();
			myTable.deleteTimer(dataSet);
      myTable.insertTimer(dataSet);
      myTable.searchTimer(dataSet);
    }
    if (option==6){
      cout << "Load factor 1 times: " << endl;
      for (int i=0; i<10009; i++){
        myTable.insert(dataSet[i]);
      }
			// myTable.printTable();
			myTable.deleteTimer(dataSet);
      myTable.insertTimer(dataSet);
      myTable.searchTimer(dataSet);
    }
  }
	// myTable.printTable();
  inStream.close();

	return 0;
}
