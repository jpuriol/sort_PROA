 
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <math.h>
using namespace std;



bool RandomVector( vector<int> &, int, int, mt19937);
void CountSort(vector<int> &, int);
void LSDRadixSortVector(vector<int> &, int);
	void ConcatenarVector(vector<int> &, const vector <int> &);
	int Digito(int, int);
    
bool RandomList( list<int> &, int, int, mt19937);
void LSDRadixSortLista(list<int> &, int);


/**
* @file sort_test.cpp
*
* Prácticas de PROA
* Práctica 1.
*
* @author Ignacio Gomis Lli
* @author Juan Pablo Uriol Balbin
* @date 28/09/2017
* @version 1.0
*/


int main() 
{
	int LOW = 0;
	int UPP1 = 65535;
	vector<int> vect(10000);
    list<int> lista(10000);
    vector<int> vectAux(10000);
    list<int> listaAux(10000);

    srand(time(NULL));
	const int SEED = rand();
	std::mt19937 aleatorio (SEED);
	clock_gettime(CLOCK_REALTIME, &ini_time);
	double total;
	
	
	clock_gettime(CLOCK_REALTIME, &ini_time);
	for(int i=0;i<100;i++)
	{
	RandomVector(vect,LOW,UPP1,aleatorio)
	vectAux=vect;
	CountSort(vectAux, UPP1);
	}
	clock_gettime(CLOCK_REALTIME, &fin_time);
	total=(fin_time.tv_sec-ini_time.tv_sec)+(fin_time.tv_nsec-ini_time.tv_nsec)/BILLION;
	cout << "Tiempo medio Countsort: "<<total/100;
	

	clock_gettime(CLOCK_REALTIME, &ini_time);
	for(int i=0;i<100;i++)
	{
	RandomVector(vect,LOW,UPP1,aleatorio)
	vectAux=vect;
	LSDRadixSortVector(vectAux, UPP1);
	}
	clock_gettime(CLOCK_REALTIME, &fin_time);
	total=(fin_time.tv_sec-ini_time.tv_sec)+(fin_time.tv_nsec-ini_time.tv_nsec)/BILLION;
	cout << "Tiempo medio RadixSort Vector: "<<total/100;
	
	clock_gettime(CLOCK_REALTIME, &ini_time);
		for(int i=0;i<100;i++)
		{
		RandomLista(lista,LOW,UPP1,aleatorio)
		listaAux=lista;
		LSDRadixSortLista(listaAux, UPP1);
		}
		clock_gettime(CLOCK_REALTIME, &fin_time);
		total=(fin_time.tv_sec-ini_time.tv_sec)+(fin_time.tv_nsec-ini_time.tv_nsec)/BILLION;
		cout << "Tiempo medio RadixSort Lista: "<<total/100;
	
return 0;
}


/**
*
* Generará un vector de enteros aleatorios
*
* @param[out] vect Vector de enteros con tamaño asignado
* @param[in] lowlim Limite inferior aleatorio
* @param[in] uplim Limite superior aleatorio
* @return True if lowlim <= uplim False if lowlim>uplim
*/

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

/**
*
* Aplicará el algoritmo CountSort sobre un vector
*
*
* @param vect Vector a ordenar
* @param max Número maximo que puede alcanzar el vector
*
*/

void CountSort(vector<int> & vect, int max)
{
		unsigned n = vect.size();
	
		vector<int> vect2 (n);
		
		vector <int> aux( max+1 );

		for(unsigned i = 0; i < n; i++)
		
			aux[ vect[ i ] ] = aux[ vect[ i ] ] + 1;
			
		for(int i = 1; i < max; i++)	
			
			aux[i] += aux[i - 1];
        
			
        for(int j = n; j >= 0; j--)
		{
            
			vect2[ aux[ vect[ j ]] -1  ]=vect[ j ];
            
			aux[ vect[ j ]] -= 1;
			
		}
			
		vect=vect2;
}

/**
*
* Aplicará el algoritmo LSDRadixSort sobre un vector
*
*
* @param vect Vector a ordenar
* @param max Número maximo que puede alcanzar el vector
*
*/

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

/**
*
* Concatenacion de 2 vectores
*
*
* @param v1 Vector inicial
* @param v2 Vector a insertar tras v1
*
*/

void ConcatenarVector(vector<int> & v1, const vector <int> & v2)
{
	for(unsigned i = 0;i < v2.size(); i++)
		v1.push_back( v2[i] );
}

/**
*
* Obtiene un digito de un entero
*
*
* @param posicion Indice de posición que obtener el digito del numero.
* @param num Numero del cual obtener el digito.
*
*/


int Digito(int posicion, int num)
{
	int aux = pow( 10 , posicion );
	aux = num / aux;
	aux = aux % 10;
	return aux;
}

/**
*
* Generará una lista de enteros aleatorios
*
* @param lista Lista de enteros con tamaño asignado
* @param lowlim Limite inferior aleatorio
* @param uplim Limite superior aleatorio
* @return True if lowlim <= uplim False if lowlim>uplim
*/

bool RandomList( list<int> & lista, int lowlim, int uplim, mt19937 aleatorio)
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

/**
*
* Aplicará el algoritmo LSDRadixSort sobre una lista
*
*
* @param lista Lista a ordenar
* @param max Número maximo que puede alcanzar la lista
*
*/

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


