#pragma once
/*
Klasa odpowiedzialna za aktualizowanie ruchów na planszy
Klasa odpowiedzialna za sprawdzanie zwyciêskich ruchów
Klasa rysuj¹ca planszê
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
#define MAX 6
class Plansza
{
	char tab[MAX][MAX];
	char pom[MAX][MAX];
public:
	void initBoard(); // inicjalizuj plansze (wypelnij +)
	bool setPole(int, int, char); // zaznacz pole na planszy
	void wypiszPlansze();
	void zapiszPlansze(fstream&);
	void wczytajPlansze(fstream&);
	void obrocPlansze(string); // do wykonania obracania w zaleznosci od tego czy jest to gracz Komputerowy czy ludzki
	template<typename T, size_t wym>
	void rotLeft(T(&rotLeft)[wym][wym], int cwiartka); //obroc cwiartke w lewo
	template<typename T, size_t wym>
	void rotRight(T(&rotRight)[wym][wym], int cwiartka); //obroc  cwiartke w prawo
	bool checkWin(); //sprawdz wygrana
	~Plansza() {};
};

