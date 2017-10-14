#include "sort.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <math.h>
using namespace std;

/*int main()
{
	int LOW { 0 };
	int UPP1 { 255 };
	int UPP2 { 65535 };
	vector<int> vect(20);
    list<int> lista(20);

	const int SEED { 1413815 };
	std::mt19937 aleatorio (SEED);



	cout<<"Count Sort"<<endl;

	if(RandomVector(vect,LOW,UPP1,aleatorio))
	{
		for(unsigned i = 0; i < vect.size(); i++)
		{
			cout<< vect[i] <<" ";
			if(i%10==9)
				cout<<endl;
		}
		cout<<endl;

		CountSort(vect, UPP1);

		for(unsigned i = 0; i < vect.size(); i++)
		{
			cout<< vect[i] <<" ";
			if(i%10==9)
				cout<<endl;
		}
		cout<<endl;

	}

	if(RandomVector(vect,LOW,UPP2,aleatorio))
	{
		for(unsigned i = 0; i < vect.size(); i++)
		{
			cout<< vect[i] <<" ";
			if(i%10==9)
				cout<<endl;
		}
		cout<<endl;

		CountSort(vect, UPP2);

		for(unsigned i = 0; i < vect.size(); i++)
		{
			cout<< vect[i] <<" ";
			if(i%10==9)
				cout<<endl;
		}
		cout<<endl;

	}

	cout<<"LSDRadixSortVector"<<endl;

	if(RandomVector(vect,LOW,UPP1,aleatorio))
	{
		for(unsigned i = 0; i < vect.size(); i++)
		{
			cout<< vect[i] <<" ";
			if(i%10==9)
				cout<<endl;
		}
		cout<<endl;

		LSDRadixSortVector(vect, UPP1);

		for(unsigned i = 0; i < vect.size(); i++)
		{
			cout<< vect[i] <<" ";
			if(i%10==9)
				cout<<endl;
		}
		cout<<endl;
	}

	cout<<endl;

	if(RandomVector(vect,LOW,UPP2,aleatorio))
	{
		for(unsigned i = 0; i < vect.size(); i++)
		{
			cout<< vect[i] <<" ";
			if(i%10==9)
				cout<<endl;
		}
		cout<<endl;

		LSDRadixSortVector(vect, UPP2);

		for(unsigned i = 0; i < vect.size(); i++)
		{
			cout<< vect[i] <<" ";
			if(i%10==9)
				cout<<endl;
		}
		cout<<endl;
	}

	cout<<endl<<"LSDRadixSortLista"<<endl;
	int cont=0;

	if(RandomList(lista,LOW,UPP1,aleatorio))
	{
		auto iter=lista.begin();
        while(iter!=lista.end())
        {
            cout<<*iter<<" ";
            iter++;
            cont++;
            if(cont==10)
            {
                cont=0;
                cout<<endl;
            }
        }
		cout<<endl;

		LSDRadixSortLista(lista, UPP1);

		iter=lista.begin();
        while(iter!=lista.end())
        {
            cout<<*iter<<" ";
            iter++;
            cont++;
            if(cont==10)
            {
                cont=0;
                cout<<endl;
            }
        }

	}

	cout<<endl;

	if(RandomList(lista,LOW,UPP2,aleatorio))
	{
		auto iter=lista.begin();
        while(iter!=lista.end())
        {
            cout<<*iter<<" ";
            iter++;
            cont++;
            if(cont==10)
            {
                cont=0;
                cout<<endl;
            }
        }
		cout<<endl;

		LSDRadixSortLista(lista, UPP2);

		iter=lista.begin();
        while(iter!=lista.end())
        {
            cout<<*iter<<" ";
            iter++;
            cont++;
            if(cont==10)
            {
                cont=0;
                cout<<endl;
            }
        }
		cout<<endl;
	}


return 0;
}*/


bool RandomVector( vector<int> & vect, int lowlim, int uplim, mt19937 aleatorio)
{
	if(lowlim <= uplim)
	{
		for(unsigned i = 0; i < vect.size(); i++)
		{
			vect[i] = ( ( aleatorio() % (uplim - lowlim+1) ) + lowlim);
		}
		return true;
	}
	else
		return false;
}


vector<int> CountSort(const vector<int> & unsorted, int max)
{
		vector<int> sorted( unsorted.size() );
		vector<int> aux(max);

		for(unsigned i = 0; i < unsorted.size(); i++)
			aux[ unsorted[i] - 1 ]++;  //aux[i] contiene cuantas veces aparece i+1 en v

		for(int i = 1; i < max; i++)
			aux[i] += aux[i-1];  //aux[i] contiene en que pos tiene que ir i+

		cout << "aux[ unsorted[i] - 1 ] - 1 ]" << endl;
		for(int i = unsorted.size() - 1; i >= 0; i--)
		{
			cout << "[" << aux[ unsorted[i] - 1 ] - 1 << "]";
			sorted[ aux[ unsorted[i] - 1 ] - 1 ]= unsorted[i];
			aux[ unsorted[i] - 1 ]--;
		}
		cout<<endl;

		return sorted;
}


void LSDRadixSortVector(vector<int> & vect, int max)
{
	vector<int> vacio(0);
	int d;
	unsigned n=vect.size();
	vector<vector<int> > aux(n);

	for(unsigned i = 0;i <= log10(max)+1; i++)
	{
		for(unsigned j = 0; j < 10; j++)
		{
			aux[j] = vacio;
		}
		for(unsigned j = 0; j < n; j++)
		{

			d = Digito( i, vect[j] );
			aux[d].push_back( vect[j] );
		}
		for(unsigned j = 1; j < n; j++)
			ConcatenarVector(aux[0], aux[j]);
		vect = aux[0];
	}
}


void ConcatenarVector(vector<int> & v1, const vector <int> & v2)
{
	for(unsigned i = 0;i < v2.size(); i++)
		v1.push_back( v2[i] );
}


int Digito(int posicion, int num)
{
	int aux = pow( 10 , posicion );
	aux = num / aux;
	aux = aux % 10;
	return aux;
}


bool RandomList (list<int> & lista, int lowlim, int uplim, mt19937 aleatorio)
{
    int num;
	if(lowlim <= uplim)
	{
        auto iter=lista.begin();
        while(iter!=lista.end())
        {
            num=aleatorio()% (uplim - lowlim+1)+ lowlim;
            *iter = num;
            std::advance(iter,1);
        }
        return true;
	}
	else
		return false;
}


void LSDRadixSortLista(list<int> & lista, int max)
{
	list<int> vacio(0);
	int d;
	unsigned n=lista.size();
	vector<list<int> > aux(n);



	for(unsigned i = 0;i <= log10(max)+1; i++)
	{
        for(unsigned j = 0; j < 10; j++)
		{
			aux[j] = vacio;
		}

        auto iter=lista.begin();
        while(iter!=lista.end())
        {
            d = Digito( i, *iter );
            aux[d].push_back( *iter );
            std::advance(iter,1);
        }

        for(unsigned j = 1; j < n; j++)
			aux[0].insert(aux[0].end(),aux[j].begin(),aux[j].end());
		lista = aux[0];


	}
}
