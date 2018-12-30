#include <iostream>
#include <fstream>
#include "Funkcje.h"

using namespace std;

void wczytywanie(ifstream & plik, wierzcholek * & pHead)
{
	char obecny_znak, obecny_wierzcholek=0;
	bool czy_sasiad = 0;
	while (plik >> obecny_znak)
	{
		if (obecny_znak == '-')
		{
			pHead = new wierzcholek{ obecny_wierzcholek, nullptr, nullptr };
			break;
		}
		if ((obecny_znak > 47 && obecny_znak < 58) || obecny_znak > 64)
			obecny_wierzcholek = obecny_znak;
	}
	char ostatni=0;
	while (plik >> obecny_znak)
	{
		if (obecny_znak == '-')
		{
			auto p = pHead;
			wierzcholek * pNowy = new wierzcholek{ obecny_wierzcholek, nullptr, nullptr };
			ostatni = obecny_wierzcholek;
			if (pHead->wNext == nullptr || pHead->nazwa==obecny_wierzcholek)
			{
				if (obecny_wierzcholek != pHead->nazwa)
				{
					pHead->wNext = pNowy;
				}
				else continue;
					
			}
			else while (p->wNext)
			{
				p = p->wNext;
				if (obecny_wierzcholek == p->nazwa)
				{
					czy_sasiad++;
					break;
				}
			}
			if (czy_sasiad == 0)
				p->wNext = pNowy;
			czy_sasiad = 0;
		};
		if (obecny_znak == '>')
		{
			plik >> obecny_wierzcholek;
			auto wsk = pHead;
			sasiad * pNowy = new sasiad{ obecny_wierzcholek, nullptr };
			if (pHead->wNext == nullptr || pHead->nazwa==ostatni)
			{
				if (pHead->pierwszy == nullptr)
					pHead->pierwszy = pNowy;
				else
				{
					auto p = wsk->pierwszy;
					while (p->sNext)
						p = p->sNext;
					p->sNext = pNowy;
				}
			}
			else while (wsk->wNext)
			{
				wsk = wsk->wNext;
				if (ostatni == wsk->nazwa)
				{
					
					if (wsk->pierwszy==nullptr)
						wsk->pierwszy = pNowy;
					else
					{
						auto p = wsk->pierwszy;
						while (p->sNext)
							p = p->sNext;
						p->sNext = pNowy;
					
					}
				}
				
			}
		}
		if ((obecny_znak > 47 && obecny_znak < 58) || obecny_znak > 64)
			obecny_wierzcholek = obecny_znak;
	}
}
void wypiszOdPoczatkuRekurencyjnie(wierzcholek * pHead)
{
	if (pHead)
	{   
		while (pHead) 
		{
			cout << pHead->nazwa<< " -> ";
			auto p = pHead->pierwszy;
			cout << pHead->pierwszy->nazwa<<" ";
			while (p->sNext)
			{
				p = p->sNext;
				cout << p->nazwa<< " ";
			}
			cout << endl;
			pHead = pHead->wNext;
		}
	}
}
