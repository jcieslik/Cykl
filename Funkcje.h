#ifndef FUNKCJE_H
#define FUNKCJE_H
struct sasiad
{
	char nazwa;
	sasiad *sNext;
};
struct wierzcholek
{
	char nazwa;
	wierzcholek *wNext;
    sasiad *pierwszy;
};
void wczytywanie(std::ifstream & plik, wierzcholek * & pHead);
void wypiszOdPoczatkuRekurencyjnie(wierzcholek * pHead);
#endif FUNKCJE_H
