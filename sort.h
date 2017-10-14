#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <math.h>
using namespace std;


bool RandomVector( vector<int> &, int, int, mt19937);
vector<int> CountSort(const vector<int> &, int);
void LSDRadixSortVector(vector<int> &, int);
void ConcatenarVector(vector<int> &, const vector <int> &);
int Digito(int, int);
bool RandomList( list<int> &, int, int, mt19937);
void LSDRadixSortLista(list<int> &, int);

#endif  // GTEST_SAMPLES_SAMPLE1_H_
