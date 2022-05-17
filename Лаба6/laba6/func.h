#ifndef LABA6_FUNC_H
#define LABA6_FUNC_H
#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
using namespace std;
struct Node{ //структура вузла
    int data;
    int level;
    Node *left, *right;
    Node(int d, int l): data(d), left(NULL), right(NULL), level(l){};
};
Node* makeTree(vector<int>, int, int, int); //метод створення дерева
void outputTree(Node*); //метод обходу дерева
vector<int> genArr(int n); //метод генерації послідовності чисел
void printArr(vector<int> m); //метод виведення послідовності чисел
void printNodes(Node*); //метод виведення внутрішніх вузлів дерева
#endif
