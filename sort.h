#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <math.h>
using namespace std;


bool RandomVector( vector<int> &, int, int, mt19937 &);
void CountSort(vector<int> &, int);
void RadixSortVector(vector<int> &, int);
bool RandomList( list<int> &, int, int, mt19937 &);
void RadixSortList(list<int> &, int);
void PrintVector(const vector<int> &);
void PintList(const list<int> &);

#endif
