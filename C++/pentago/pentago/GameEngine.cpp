#include "Gracze.h"
#include "Plansza.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
// dodawanie nowego wyniku do tabeli wyników (PLIKU TEKSTOWEGO CHWA£Y)
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
	string komunikat = "Zanim zaczniemy, chcia³bym wyjaœniæ Ci parê zasad...\n\n"
		"W grze wystêpuj¹ dwa tryby, Gra z Komputerem oraz gra wieloosobowa.\n"
		"Plansza podzielona jest na cztery czêœci, gra polega na tym, ¿e po ka¿dym ruchu\n"
		"obracasz któr¹œ z nich.\n"
		"Je¿eli ustawisz 5 w³asnych pionków obok siebie, w rzêdzie, kolumnie lub na skos to\n wygrasz!\n"
		"Mo¿esz równie¿ przechytrzyæ przeciwnika i obróciæ tak planszê, aby Twoje pionki ustawi³y siê obok siebie.\n"
		"Plansza numerowana jest cyframi 1,2,3,4 w kolejnoœci Lewa Górna, Prawa Górna, Lewa Dolna, Prawa Dolna.\n"
		"W grze wystêpuje kontrola danych. Gdy minie jedna runda, zostaniesz zapytany/na czy chce przerwaæ grê.\n"
		"Wtedy wciœnij przycisk o który proszê, to gra zostanie przerwana. Bêdziesz w stanie j¹ zapisaæ, wczytaæ lub rozpocz¹æ now¹.\n"
		"Po przerwaniu gry, nie jest mo¿liwa jej dalsza kontynuacja. Musisz j¹ zapisaæ i wczytaæ.\n"
		"W grze dostêpna jest Tabela Wyników. Kiedy wygrasz, poproszê Ciê o imiê, i dopiszê do \n\nPLIKU TEKSTOWEGO CHWA£Y!!!\n\n"
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
		cout << "B³¹d otwarcia tabeli wyników. SprawdŸ lokalizacjê i otwórz program jeszcze raz." << endl;
	}
	cout << "Witaj w Pentago! Czy chcesz wyœwietliæ samouczek?\nWpisz \'1\' je¿eli chcesz wyœwietliæ samouczek lub jak¹kolwiek inn¹ cyfrê \naby pomin¹æ." << endl;
	int wyswietlSamouczek; // zmienna decyduj¹ca o tym czy u¿ytkonwnik chce zobaczyæ samouczek
	cin >> wyswietlSamouczek;
	while (!cin) { // kontrola danych, dopóki dane nie bêd¹ cyfr¹ wyczyœæ bufor od pocz¹tku a¿ do MAX lub wyst¹pienia znaku \n
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> wyswietlSamouczek;
	}
	if (wyswietlSamouczek == 1) {
		sayHello(); // wyswietla zasady gry.
	}
	int nn = 0, mm = 0; // licznik rund
	bool win = false;
	bool winHuman = false; // zmienne bool do rozró¿nienia która gra by³a rozegrana
	bool winComp = false; //
	bool wczytano = false; // zmienna bool do rozstrzygniêcia czy inicjalizowaæ nowa plansze.
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
				cout << "Twój ruch." << endl;

				czlowiek->wykonajRuchX();
				czlowiek->wykonajRuchY();
				//Dopóki siê nie uda ustaliæ pola to bêdzie pytaæ o wiersz i kolumne do ustalenia.
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
					cout << endl << "Wygra³eœ Grê !!!" << endl;
					string imie;
					cout << "Podaj swoje imiê: ";
					cin >> imie;
					while (!cin)
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "B³êdne dane, spróbuj ponownie" << endl;
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
					cout << "Je¿eli chcesz przerwaæ grê, wpisz \'T\' ";
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
					cout << "Podaj swoje imiê: ";
					cin >> imie;
					while (!cin)
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "B³êdne dane, spróbuj ponownie" << endl;
						cin >> imie;
					}
					dodajDoTabeli(fp, imie, nn + 1);
					win = true;
				}
				else if (graczDrugi->getWygrana() == true) { 
					cout << endl << "Wygrywa drugi Gracz!!!" << endl;
					string imie;
					cout << "Podaj swoje imiê: ";
					cin >> imie;
					while (!cin)
					{
						cin.clear();
						cin.ignore(INT_MAX, '\n');
						cout << "B³êdne dane, spróbuj ponownie" << endl;
						cin >> imie;
					}
					dodajDoTabeli(fp, imie, nn + 1);
					win = true;
				}
				if (win != true) {

					cout << "Je¿eli chcesz przerwaæ grê, wpisz \'T\' ";
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
				cout << "¯ADEN ŒMIERTELNIK NIE DOST¥PI£ JESZCZE ZASZCZYTU ZAPISANIA SIÊ NA STRONNICACH \nPLIKU TEKSTOWEGO CHWA£Y... \nNie wczytano ¿adnych danych" << endl;
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
			cout << "Chcesz wczytaæ ostatni zapis z 1) Komputerem 2) Gry wieloosobowej? :";
			cin >> wyborwczyt;
			while (!cin && wyborwczyt < 1 || wyborwczyt > 2) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "B³êdne dane, spróbuj ponownie: ";
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
					cout << "Plik zapisu jest pusty. Nie wczytano ¿adnych danych" << endl;
				}
				else
				{
					cout << "Wczytano grê z komputerem." << endl;
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
					cout << "Plik zapisu jest pusty. Nie wczytano ¿adnych danych" << endl;
				}
				else
				{
					cout << "Wczytano grê wieloosobow¹." << endl;
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
					cout << "Zapisano grê z komputerem." << endl;
					plik.close();
				}
				else
					cout << "Nie mo¿esz zapisaæ wygranej gry." << endl;

			}
			else if (ostatniaGra == "Czlowiek") {
				if (winHuman != true) {
					plik.open("savegamehuman.txt", ios::out);
					system("CLS");
					plansza.zapiszPlansze(plik);
					cout << "Zapisano grê wieloosobow¹." << endl;
					plik.close();
				}
				else
					cout << "Nie mo¿esz zapisaæ wygranej gry." << endl;
			}

			if (ostatniaGra == "")
			{
				cout << "Nie rozegrano ¿adnej gry!" << endl;
			}
			break;
		}
		case 6: //Wyjœcie
		{
			system("CLS");
			char wyjscie;
			cout << "Czy na pewno chcesz wyjœæ z gry? Wszystkie niezapisane zmiany zostan¹ utracone! [T/N]" << endl;
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
			cout << "B³êdny wybór, spróbuj ponownie" << endl;
			wybor = menu.showMenu();
		}
	}
}