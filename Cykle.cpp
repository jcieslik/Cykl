#include <iostream>
#include <fstream>
#include "Funkcje.h"

using namespace std;

int main()
{
	ifstream plik;
	wierzcholek * pGlowa = nullptr;
	plik.open("Graf.txt");
	if(plik.good())
    {
		wczytywanie(plik, pGlowa);
		wypiszOdPoczatkuRekurencyjnie(pGlowa);
		plik.close();
	}
	return 0;
}