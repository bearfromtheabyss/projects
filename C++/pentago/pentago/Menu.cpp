#include "Menu.h"

int Menu::showMenu()
{
	int wybor;
	cout << "Menu:" << endl;
	cout << "1. Graj z komputerem" << endl;
	cout << "2. Tryb wieloosobowy" << endl;
	cout << "3. Tabela wyników" << endl;
	cout << "4. Wczytaj grê" << endl;
	cout << "5. Zapisz grê" << endl;
	cout << "6. Wyjœcie" << endl;
	cout << "> ";
	cin >> wybor;
	while (!cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "B³êdne dane, spróbuj ponownie: " << endl;
		cin >> wybor;
	}
	return wybor;
}
