#include "sort.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <math.h>
using namespace std;

const int BASE_NUM = 16;

bool RandomVector( vector<int> & vect, int lowlim, int uplim, mt19937 & aleatorio)
{
	uniform_int_distribution<> dis(lowlim, uplim);
	if(lowlim <= uplim)
	{
		for(unsigned i = 0; i < vect.size(); i++)
			vect[i] = dis(aleatorio); 
		return true;
	}
	else
		return false;
}


void CountSort(vector<int> & vectorToSort, int max)
{
		vector<int> sorted( vectorToSort.size() );
		vector<int> aux(max);

		for(unsigned i = 0; i < vectorToSort.size(); i++)
			aux[ vectorToSort[i] - 1 ]++;  ///< aux[i] contiene cuantas veces aparece i+1 en v

		for(int i = 1; i < max; i++)
			aux[i] += aux[i-1];  ///< aux[i] contiene en que pos tiene que ir i+1

		for(int i = vectorToSort.size() - 1; i >= 0; i--)
		{
			sorted[ aux[ vectorToSort[i] - 1 ] - 1 ]= vectorToSort[i];
			aux[ vectorToSort[i] - 1 ]--;
		}

		vectorToSort = sorted;
	}


int Digito(int, int);
void ConcatenarVector(vector<int> &, const vector <int> &);
void RadixSortVector(vector<int> & vectorToSort, int max)
{
  unsigned n = vectorToSort.size();
	int d;
	vector< vector<int> > aux(BASE_NUM);

	unsigned iterations = log2(max) / 4;
  for(unsigned i = 0; i <= iterations; i++)
  {
    for(unsigned j = 0; j < BASE_NUM; j++)
			aux[j].clear();

    for(unsigned j = 0; j < n; j++)
    {
			d = Digito( i, vectorToSort[j] );
			aux[d].push_back( vectorToSort[j] );
		}
		vectorToSort = aux[0];
		for(unsigned j = 1; j < BASE_NUM; j++)
			ConcatenarVector(vectorToSort, aux[j]);
	}
}


void ConcatenarVector(vector<int> & v1, const vector <int> & v2)
{
	for(unsigned i = 0;i < v2.size(); i++)
		v1.push_back( v2[i] );
}

int Digito(int pos, int num)
{
	for(int i = 0; i < pos; i++)
		num = num >> 4;
	num = num % BASE_NUM;
	return num;
}


bool RandomList (list<int> & lista, int lowlim, int uplim, mt19937 & aleatorio)
{
	uniform_int_distribution<> dis(lowlim, uplim);
	if(lowlim <= uplim)
	{
        auto iter=lista.begin();
        while(iter!=lista.end())
        {
            *iter = dis(aleatorio); 
            std::advance(iter,1);
        }
        return true;
	}
	else
		return false;
}


void RadixSortList(list<int> & lista, int max)
{
	int d;
	vector<list<int> > aux(BASE_NUM);

	for(unsigned i = 0;i < log10(max); i++)
	{
    for(unsigned j = 0; j < BASE_NUM; j++)
			aux[j].clear();

			auto iter=lista.begin();
			while(iter!=lista.end())
			{
					d = Digito( i, *iter );
					aux[d].push_back( *iter );
					std::advance(iter,1);
			}

      for(unsigned j = 1; j < BASE_NUM; j++)
				aux[0].splice(aux[0].end(), aux[j]);
		lista = aux[0];
	}
}


void PrintVector(const vector<int> & vect) 
{
	for(auto v : vect)
		cout << "[" << v << "]";
	cout << endl; 
}
void PintList(const list<int> & lis) 
{
	for(auto l : lis)
		cout << "[" << l <<"]";
	cout << endl;
}
