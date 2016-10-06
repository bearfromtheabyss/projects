#include "Gracze.h"

void GraczCzlowiek::wykonajRuchX()
{
	cout << "wiersz [0-5]: ";
	cin >> ruch_x;
	while (!cin)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "B³êdne dane, spróbuj ponownie: " << endl;
		cin >> ruch_x;
	}
	//return ruch_x;
}
void GraczCzlowiek::wykonajRuchY() {
	cout << "kolumna [0-5]: ";
	cin >> ruch_y;
	while (!cin)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "B³êdne dane, spróbuj ponownie: " << endl;
		cin >> ruch_y;
	}
}

void  GraczKomputer::wykonajRuchX()
{
	ruch_x = rand() % 5 + 0;
}

void GraczKomputer::wykonajRuchY() {
	ruch_y = rand() % 5 + 0;
}

char Gracz::getZnak()
{
	return znak;
}
