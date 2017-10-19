#include <iostream>
#include "sort.h"
using namespace std;

int main(/*int argc, char **argv*/)
{
  double BILLION = 1000000000;
	int LOW = 0;
	int UPP1 = 65535;
	vector<int> vect(10000);
	list<int> lista(10000);
	vector<int> vectAux(10000);
	list<int> listaAux(10000);

	struct timespec ini_time,fin_time;
	srand(time(NULL));
	const int SEED = rand();
	std::mt19937 aleatorio(SEED);
	double total;

	clock_gettime(CLOCK_REALTIME, &ini_time);
	for (int i = 0; i < 1000; i++) {
		RandomVector(vect, LOW, UPP1, aleatorio);
		vectAux = vect;
		CountSort(vectAux, UPP1);
	}
	clock_gettime(CLOCK_REALTIME, &fin_time);
	total = (fin_time.tv_sec - ini_time.tv_sec)
			+ (fin_time.tv_nsec - ini_time.tv_nsec) / BILLION;
	cout << "Tiempo medio Countsort: " << total / 1000<<endl;

	clock_gettime(CLOCK_REALTIME, &ini_time);
	for (int i = 0; i < 1000; i++) {
		RandomVector(vect, LOW, UPP1, aleatorio);
		vectAux = vect;
    RadixSortVector(vectAux, UPP1);
	}
	clock_gettime(CLOCK_REALTIME, &fin_time);
	total = (fin_time.tv_sec - ini_time.tv_sec)
			+ (fin_time.tv_nsec - ini_time.tv_nsec) / BILLION;
	cout << "Tiempo medio RadixSort Vector: " << total / 1000<<endl;

	clock_gettime(CLOCK_REALTIME, &ini_time);
	for (int i = 0; i < 1000; i++) {
		RandomList(lista, LOW, UPP1, aleatorio);
		listaAux = lista;
		RadixSortList(listaAux, UPP1);
	}
	clock_gettime(CLOCK_REALTIME, &fin_time);
	total = (fin_time.tv_sec - ini_time.tv_sec)
			+ (fin_time.tv_nsec - ini_time.tv_nsec) / BILLION;
  cout << "Tiempo medio RadixSort Lista: " << total / 1000<<endl;
  

  return 0;
}