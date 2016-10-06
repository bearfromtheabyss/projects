#include "Gracze.h"
#include "Plansza.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
// dodawanie nowego wyniku do tabeli wynik�w (PLIKU TEKSTOWEGO CHWA�Y)
void dodajDoTabeli(fstream & fp, string imie, int nn) 
{
	time_t teraz = time(0);
	char *data = ctime(&teraz);
	fp << "Gra z komputerem" << endl;
	fp << "Data: " << data;
	fp << "Wygrana Gracza " << imie << endl;
	fp << "Wykonano " << nn << " rund" << endl;
}
void sayHello()
{
	int i = 0;
	string komunikat = "Zanim zaczniemy, chcia�bym wyja�ni� Ci par� zasad...\n\n"
		"W grze wyst�puj� dwa tryby, Gra z Komputerem oraz gra wieloosobowa.\n"
		"Plansza podzielona jest na cztery cz�ci, gra polega na tym, �e po ka�dym ruchu\n"
		"obracasz kt�r�� z nich.\n"
		"Je�eli ustawisz 5 w�asnych pionk�w obok siebie, w rz�dzie, kolumnie lub na skos to\n wygrasz!\n"
		"Mo�esz r�wnie� przechytrzy� przeciwnika i obr�ci� tak plansz�, aby Twoje pionki ustawi�y si� obok siebie.\n"
		"Plansza numerowana jest cyframi 1,2,3,4 w kolejno�ci Lewa G�rna, Prawa G�rna, Lewa Dolna, Prawa Dolna.\n"
		"W grze wyst�puje kontrola danych. Gdy minie jedna runda, zostaniesz zapytany/na czy chce przerwa� gr�.\n"
		"Wtedy wci�nij przycisk o kt�ry prosz�, to gra zostanie przerwana. B�dziesz w stanie j� zapisa�, wczyta� lub rozpocz�� now�.\n"
		"Po przerwaniu gry, nie jest mo�liwa jej dalsza kontynuacja. Musisz j� zapisa� i wczyta�.\n"
		"W grze dost�pna jest Tabela Wynik�w. Kiedy wygrasz, poprosz� Ci� o imi�, i dopisz� do \n\nPLIKU TEKSTOWEGO CHWA�Y!!!\n\n"
		"Powodzenia w grze!\n";
	while (komunikat[i] != '\0') {
		cout << komunikat[i];
		_sleep(20);
		i++;
	}
}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, ""); // polskie znaki w konsoli
	fstream fp;
	fp.open("tabela.txt", ios::in | ios::app);
	if (fp.is_open() != true) {
		cout << "B��d otwarcia tabeli wynik�w. Sprawd� lokalizacj� i otw�rz program jeszcze raz." << endl;
	}
	cout << "Witaj w Pentago! Czy chcesz wy�wietli� samouczek?\nWpisz \'1\' je�eli chcesz wy�wietli� samouczek lub jak�kolwiek inn� cyfr� \naby pomin��." << endl;
	int wyswietlSamouczek; // zmienna decyduj�ca o tym czy u�ytkonwnik chce zobaczy� samouczek
	cin >> wyswietlSamouczek;
	while (!cin) { // kontrola danych, dop�ki dane nie b�d� cyfr� wyczy�� bufor od pocz�tku a� do MAX lub wyst�pienia znaku \n
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> wyswietlSamouczek;
	}
	if (wyswietlSamouczek == 1) {
		sayHello(); // wyswietla zasady gry.
	}
	int nn = 0, mm = 0; // licznik rund
	bool win = false;
	bool winHuman = false; // zmienne bool do rozr�nienia kt�ra gra by�a rozegrana
	bool winComp = false; //
	bool wczytano = false; // zmienna bool do rozstrzygni�cia czy inicjalizowa� nowa plansze.
	Plansza plansza; 
	Gracz *czlowiek = new GraczCzlowiek(false, 'X'); // obiekt klasy ludzkiego gracza
	Gracz *komputer = new GraczKomputer(false, 'O'); // obiekt klasy komputerowego gracza
	Menu menu; // obiekt klasy odpowiedzialnej za wypisanie menu
	string ostatniaGra = ""; //zmienna do okreslenia typu zapisu; jaka gra byla ostatnia do zapisu
	//plansza.initBoard();
	while (1) {
		int wybor;
		wybor = menu.showMenu();
		switch (wybor) {
		case 1: //Graj z komputerem
			ostatniaGra = "Komputer";
			system("CLS");
			win = false;
			winComp = win;

			if (!wczytano) {
				plansza.initBoard();
			}
			while (win != true) {
				plansza.wypiszPlansze();
				cout << "Tw�j ruch." << endl;

				czlowiek->wykonajRuchX();
				czlowiek->wykonajRuchY();
				//Dop�ki si� nie uda ustali� pola to b�dzie pyta� o wiersz i kolumne do ustalenia.
				while (plansza.setPole(czlowiek->getX(), czlowiek->getY(), czlowiek->getZnak()) != true)
				{
					czlowiek->wykonajRuchX(); // setter do pola ruch_x;
					czlowiek->wykonajRuchY(); // setter do pola ruch_y;
				}
				plansza.wypiszPlansze();
				plansza.obrocPlansze("Gracz");
				plansza.wypiszPlansze();
				czlowiek->setWygrana(plansza.checkWin());

				cout << "Ruch Gracza Komputer." << endl;
				komputer->wykonajRuchX(); 
				komputer->wykonajRuchY();
				while (plansza.setPole(komputer->getX(), komputer->getY(), komputer->getZnak()) != true) {
					komputer->wykonajRuchX();
					komputer->wykonajRuchY();
				}
				plansza.wypiszPlansze();
				plansza.obrocPlansze("Komputer");
				komputer->setWygrana(plansza.checkWin()); //sprawdz plansze

				if (czlowiek->getWygrana() == true) {
					cout << endl << "Wygra�e� Gr� !!!" << endl;
					string imie;
					cout << "Podaj swoje imi�: ";
					cin >> imie;
					while (!cin)
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "B��dne dane, spr�buj ponownie" << endl;
						cin >> imie;
					}
					dodajDoTabeli(fp, imie, nn + 1);
					win = true;
				}
				else if (komputer->getWygrana() == true) {
					cout << endl << "Wygrywa Gracz Komputer" << " !!!" << endl;
					dodajDoTabeli(fp, "Komputer", nn + 1);
					win = true;
				}
				if (win != true) {
					system("CLS");
					cout << "Je�eli chcesz przerwa� gr�, wpisz \'T\' ";
					char kont;
					cin >> kont;
					if (kont == 'T')
					{
						break;
					}
					else;
				}
				nn++;
			}
			break;
		case 2: { //Graj wieloosobowo
			system("CLS");
			ostatniaGra = "Czlowiek";
			win = false;
			winHuman = win;

			if (!wczytano) {
				plansza.initBoard();
			}
			Gracz *graczDrugi = new GraczCzlowiek(false, 'W');
			//graczDrugi->setZnak('w');
			while (win != true) {
				system("CLS");
				plansza.wypiszPlansze();
				cout << "Runda pierwszego Gracza." << endl;

				czlowiek->wykonajRuchX();
				czlowiek->wykonajRuchY();

				while (plansza.setPole(czlowiek->getX(), czlowiek->getY(), czlowiek->getZnak()) != true) {
					czlowiek->wykonajRuchX();
					czlowiek->wykonajRuchY();
				}
				plansza.wypiszPlansze();
				plansza.obrocPlansze("Gracz");
				plansza.wypiszPlansze();
				czlowiek->setWygrana(plansza.checkWin());

				cout << "Runda drugiego Gracza." << endl;
				graczDrugi->wykonajRuchX();
				graczDrugi->wykonajRuchY();
				while (plansza.setPole(graczDrugi->getX(), graczDrugi->getY(), graczDrugi->getZnak()) != true)
				{
					graczDrugi->wykonajRuchX();
					graczDrugi->wykonajRuchY();
				}
				plansza.wypiszPlansze();
				plansza.obrocPlansze("Gracz");
				graczDrugi->setWygrana(plansza.checkWin()); //ustala wygrana dla gracza gdy pionki maja wygrywajace ustawienie

				if (czlowiek->getWygrana() == true) {
					cout << endl << "Wygrywa pierwszy Gracz!!!" << endl;
					string imie;
					cout << "Podaj swoje imi�: ";
					cin >> imie;
					while (!cin)
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "B��dne dane, spr�buj ponownie" << endl;
						cin >> imie;
					}
					dodajDoTabeli(fp, imie, nn + 1);
					win = true;
				}
				else if (graczDrugi->getWygrana() == true) { 
					cout << endl << "Wygrywa drugi Gracz!!!" << endl;
					string imie;
					cout << "Podaj swoje imi�: ";
					cin >> imie;
					while (!cin)
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "B��dne dane, spr�buj ponownie" << endl;
						cin >> imie;
					}
					dodajDoTabeli(fp, imie, nn + 1);
					win = true;
				}
				if (win != true) {

					cout << "Je�eli chcesz przerwa� gr�, wpisz \'T\' ";
					char kont;
					cin >> kont;
					if (kont == 'T')
					{
						break;
					}
				}
				else;
				nn++;
			}
			break;
		}
		case 3: // Tabela wynikow
		{
			system("CLS");
			if (fp.peek() == ifstream::traits_type::eof()) //sprawdzenie konca pliku
			{
				cout << "�ADEN �MIERTELNIK NIE DOST�PI� JESZCZE ZASZCZYTU ZAPISANIA SI� NA STRONNICACH \nPLIKU TEKSTOWEGO CHWA�Y... \nNie wczytano �adnych danych" << endl;
			}
			fp.seekg(0, ios::beg);
			string x;
			while (getline(fp, x)) {
				cout << x << endl;
			}
			break;
		}
		case 4: { // Wczytywanie
			system("CLS");
			int wyborwczyt;
			cout << "Chcesz wczyta� ostatni zapis z 1) Komputerem 2) Gry wieloosobowej? :";
			cin >> wyborwczyt;
			while (!cin && wyborwczyt < 1 || wyborwczyt > 2) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "B��dne dane, spr�buj ponownie: ";
				cin >> wyborwczyt;
			}
			if (wyborwczyt == 1) {
				fstream plik;
				plik.open("savegame.txt", ios::in);
				if (plik.is_open() != true)
				{
					cout << "Fatal error! Brak pliku zapisu. Nie wczytano danych." << endl;
				}
				else if (plik.peek() == ifstream::traits_type::eof())
				{
					cout << "Plik zapisu jest pusty. Nie wczytano �adnych danych" << endl;
				}
				else
				{
					cout << "Wczytano gr� z komputerem." << endl;
					wczytano = true;
				}

				plansza.wczytajPlansze(plik);
				plik.close();
			}
			else if (wyborwczyt == 2) {
				fstream plik;
				plik.open("savegamehuman.txt", ios::in);
				if (plik.is_open() != true)
				{
					cout << "Fatal error! Brak pliku zapisu. Nie wczytano danych." << endl;
				}
				else if (plik.peek() == ifstream::traits_type::eof())
				{
					cout << "Plik zapisu jest pusty. Nie wczytano �adnych danych" << endl;
				}
				else
				{
					cout << "Wczytano gr� wieloosobow�." << endl;
					wczytano = true;
				}

				plansza.wczytajPlansze(plik);
				plik.close();
			}
			break;
		}
		case 5: // Zapis
		{
			system("CLS");
			int wyborwczyt;
			fstream plik;
			if (ostatniaGra == "Komputer") {
				if (winComp != true) {
					plik.open("savegame.txt", ios::out);
					system("CLS");
					plansza.zapiszPlansze(plik);
					cout << "Zapisano gr� z komputerem." << endl;
					plik.close();
				}
				else
					cout << "Nie mo�esz zapisa� wygranej gry." << endl;

			}
			else if (ostatniaGra == "Czlowiek") {
				if (winHuman != true) {
					plik.open("savegamehuman.txt", ios::out);
					system("CLS");
					plansza.zapiszPlansze(plik);
					cout << "Zapisano gr� wieloosobow�." << endl;
					plik.close();
				}
				else
					cout << "Nie mo�esz zapisa� wygranej gry." << endl;
			}

			if (ostatniaGra == "")
			{
				cout << "Nie rozegrano �adnej gry!" << endl;
			}
			break;
		}
		case 6: //Wyj�cie
		{
			system("CLS");
			char wyjscie;
			cout << "Czy na pewno chcesz wyj�� z gry? Wszystkie niezapisane zmiany zostan� utracone! [T/N]" << endl;
			cin >> wyjscie;
			while (wyjscie != 'T' || wyjscie != 'N') {
				if (wyjscie == 'T')
				{
					delete czlowiek;
					delete komputer;					
					fp.close();
					return 0;
				}
				else if (wyjscie == 'N')
				{
					system("CLS");
					wybor = menu.showMenu();
				}
				else
					cin >> wyjscie;
			}
			break;
		}
		default:
			system("CLS");
			cout << "B��dny wyb�r, spr�buj ponownie" << endl;
			wybor = menu.showMenu();
		}
	}
}