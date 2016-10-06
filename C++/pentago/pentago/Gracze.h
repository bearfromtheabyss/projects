#pragma once
/*
Klasa Gracz - abstrakcyjna, reprezentuj¹ca pewnego gracza
Klasa GraczCzlowiek - klasa reprezentuj¹ca ludzkiego gracza. Do jej obowi¹zków nale¿y przypisanie ruchu do pewnego gracza.
Klasa GraczKomputer - klasa reprezetuj¹ca komputereowego gracza. Do jej obowi¹zków nale¿y przypisanie ruchu do pewnego gracza kompuitergowego.
Realizacja za pomoc¹ funkcji rand();
*/
#include <iostream>
using namespace std;
class Gracz
{
protected:
	bool wygrana;
	int ruch_x, ruch_y;
	char znak;
public:
	Gracz(bool wygrana, char znak) : wygrana(wygrana), znak(znak) {};
	virtual void wykonajRuchX() = 0; //do wykonywania ruchu wiersz
	virtual void wykonajRuchY() = 0; // do wykonywania ruchu kolumna
	bool getWygrana()
	{
		return wygrana;
	} // do pobrania czy gra wygrana
	void setWygrana(bool wygrana)
	{
		this->wygrana = wygrana;
	} //ustawienie flagi wygrana
	int getX() {
		return this->ruch_x;
	} //do pobrania wiersza
	int getY() {
		return this->ruch_y;
	} // do pobrania kolumny
	char getZnak(); //do pobrania znaku 
};
class GraczCzlowiek : public Gracz
{
	
public: 
	GraczCzlowiek()
	{
		znak = 'S';
		wygrana = false;
	}
	void wykonajRuchX();
	void wykonajRuchY();
	GraczCzlowiek(bool wygrana, char znak) : Gracz(wygrana, znak) {};
	~GraczCzlowiek() {};
};

class GraczKomputer : public Gracz
{
public:
	void wykonajRuchX();
	void wykonajRuchY();
	GraczKomputer(bool wygrana, char znak) : Gracz(wygrana, znak) {};
	GraczKomputer() {
		znak = 'K';
		wygrana = false;
	}
	~GraczKomputer() {};
};

