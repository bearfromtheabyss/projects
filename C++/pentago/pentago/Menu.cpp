#include "Menu.h"

int Menu::showMenu()
{
	int wybor;
	cout << "Menu:" << endl;
	cout << "1. Graj z komputerem" << endl;
	cout << "2. Tryb wieloosobowy" << endl;
	cout << "3. Tabela wynik�w" << endl;
	cout << "4. Wczytaj gr�" << endl;
	cout << "5. Zapisz gr�" << endl;
	cout << "6. Wyj�cie" << endl;
	cout << "> ";
	cin >> wybor;
	while (!cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "B��dne dane, spr�buj ponownie: " << endl;
		cin >> wybor;
	}
	return wybor;
}
