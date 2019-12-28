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

struct HashNode
{
  int key;
  struct HashNode *left;
  struct HashNode *right;
};

struct BST
{
  struct HashNode *head;
};

struct BST *array;

void insert(struct HashNode *tree, struct HashNode *item);
struct HashNode* search (struct HashNode *tree, int key);
struct HashNode* deleteKey(struct HashNode * tree, int key);
void printTable(struct HashNode* tree);

int h(int key)
{
  return (key % TABLE_SIZE);
}

void add(int key)
{
  int index=h(key);
  struct HashNode* tree = (struct HashNode*)array[index].head;

  struct HashNode* new_item= (struct HashNode*)malloc(sizeof(struct HashNode));
  new_item->key=key;
  new_item->left=NULL;
  new_item->right=NULL;

  if (tree==NULL)
  {
    array[index].head=new_item;
    size++
  }
  else{
    struct HashNode* temp= search(tree, key);
    if (temp==NULL)
    {
      insert(tree, new_item);
      size++;
    }
  }
}

struct HashNode* search(struct HashNode* tree, int key)
{
  if (tree==NULL)
  {
    return NULL;
  }
  if(tree->key==key)
  {
    return tree;
  }
  else if(key < tree->key)
  {
    return search(tree->left, key);
  }
  else
  {
    return find(tree->right, key);
  }
}

void insert(struct HashNode* tree, struct HashNode *item)
{
  if (item->key < tree->key)
        {
		if (tree->left == NULL)
                {
			tree->left = item;
			return;
		}
		else
                {
			insert(tree->left, item);
			return;
		}
	}
	else if (item->key > tree->key)
        {
		if (tree->right == NULL)
                {
			tree->right = item;
			return;
		}
		else
                {
			insert(tree->right, item);
			return;
		}
	}
}
// class HashTable {
// private:
//   HashNode* table[TABLE_SIZE];
// 	int h(int k, int functionOption);
//   int M;
// public:
// 	HashTable();
//   void insert(int k, int functionOption);
//   HashNode* search(int k, int functionOption);
//   void deleteKey(int k, int functionOption);
// 	void printTable();
//   void insertTimer(vector<int> &dataSet, int functionOption);
//   void deleteTimer(vector<int> &dataSet, int functionOption);
//   void searchTimer(vector<int> &dataSet, int functionOption);
// };
