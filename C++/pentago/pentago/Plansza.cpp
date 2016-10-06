#include "Plansza.h"
#include "Gracze.h"
void Plansza::initBoard() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			tab[i][j] = '+';
			pom[i][j] = '+';
		}
	}
}
bool Plansza::setPole(int i, int j, char znak)
{
	if (tab[i][j] == '+' && i < MAX && j < MAX) {
		tab[i][j] = znak;
		return true;
	}
	else {
		cout << "Znak tutaj ju¿ stoi, lub wychodzisz poza planszê." << endl;
		return false;
	}
}

void Plansza::wypiszPlansze()
{
	cout << "   ";
	for (int i = 0; i < 6; i++) {
		if (i != 2) {
			cout << " " << i;
		}
		else
			cout << " " << i << "  ";
	}
	cout << endl;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (j == 0) {
				cout << i << " | ";
			}

			cout << tab[i][j] << " ";
			if (j == 2) {
				cout << "| ";
			}
			if (i == 2 && j == 5)
			{
				//	cout << "\n";
			}
			if (j == 5)
			{
				cout << "|";
			}
			if (i == 2 && j == 5) {
				cout << "\n  -----------------";
			}
		}

		cout << endl;

	}
}
template<typename T, size_t wym>
void Plansza::rotLeft(T(&rotLeft)[wym][wym], int cwiartka)
{
	int przesWierszy = ((cwiartka - 1) / 2) * 3;
	int przesKolumn = ((cwiartka - 1) % 2) * 3;
	for (int i = 0 + przesWierszy; i < 3 + przesWierszy; i++) {
		for (int j = 0 + przesKolumn; j < 3 + przesKolumn; j++) {
			pom[2 - j + przesWierszy + przesKolumn][i - przesWierszy + przesKolumn] = tab[i][j];
		}
	}
	for (int i = 0 + przesWierszy; i < 3 + przesWierszy; i++) {
		for (int j = 0 + przesKolumn; j < 3 + przesKolumn; j++) {
			tab[i][j] = pom[i][j];
		}
	}
}

template<typename T, size_t wym>
void Plansza::rotRight(T(&rotRight)[wym][wym], int cwiartka)
{
	int przesWierszy = ((cwiartka - 1) / 2) * 3;
	int przesKolumn = ((cwiartka - 1) % 2) * 3;
	for (int i = 0 + przesWierszy; i < 3 + przesWierszy; i++) {
		for (int j = 0 + przesKolumn; j < 3 + przesKolumn; j++) {
			pom[j + przesWierszy - przesKolumn][2 - i + przesWierszy + przesKolumn] = tab[i][j];
		}
	}

	for (int i = 0 + przesWierszy; i < 3 + przesWierszy; i++) {
		for (int j = 0 + przesKolumn; j < 3 + przesKolumn; j++) {
			tab[i][j] = pom[i][j];
		}
	}

}
bool checkChar(string c)
{
	if (c != "l" && c != "p")
	{
		return true;
	}
	return false;
}

void Plansza::obrocPlansze(string name) { 
	int qr, i, j;                        
	int start, stop, start_j, stop_j;
	string kierunek;
	if (name == "Gracz") {
		cout << "Któr¹ æwiartkê obróciæ? [1-4]: ";
		cin >> qr;
		while (!cin || qr < 1 || qr > 4 )
		{
			cout << "B³êdne dane, æwiartki maj¹ cyfry 1, 2, 3 lub 4." << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "spróbuj ponownie: ";
			cin >> qr;
		}
		cout << "W któr¹ stronê chcesz j¹ obróciæ? [l-p]: ";
		cin >> kierunek;
		while (checkChar(kierunek)) {
			cout << "B³êdne dane!" << endl;
			cin >> kierunek;
		}

	}
	else if (name == "Komputer") {
		qr = rand() % 4 + 1;
		int kier = rand() % 2 + 1;
		if (kier == 1) {
			kierunek == "l";
		}
		else if (kier == 2)
			kierunek == "p";
		else
			kierunek == "l";
	}
	if (qr == 1) {
		if (kierunek == "l")
		{
			rotLeft(tab, qr);
		}
		else if (kierunek == "p") {

			rotRight(tab, qr);

		}
	}
	else if (qr == 2) {
		if (kierunek == "l")
		{
			rotLeft(tab, qr);
		}
		else if (kierunek == "p") {
			rotRight(tab, qr);
		}

	}
	else if (qr == 3) {
		if (kierunek == "l")
		{
			rotLeft(tab, qr);
		}
		else if (kierunek == "p") {
			rotRight(tab, qr);
		}
	}
	else if (qr == 4) {
		if (kierunek == "l")
		{
			rotLeft(tab, qr);
		}
		else if (kierunek == "p") {
			rotRight(tab, qr);
		}
	}
}


bool Plansza::checkWin() {
	bool wygrana = false;
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (tab[i][j] == tab[i][j + 1] && tab[i][j + 1] == tab[i][j + 2] && tab[i][j + 2] == tab[i][j + 3] && tab[i][j + 3] == tab[i][j + 4] && tab[i][j] != '+') {
				wygrana = true;
			} //kolumna
			else if (tab[i][j] == tab[i + 1][j] && tab[i + 1][j] == tab[i + 2][j] && tab[i + 2][j] == tab[i + 3][j] && tab[i + 3][j] == tab[i + 4][j] && tab[i][j] != '+') {
				wygrana = true;
			} //wiersz
		}
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (tab[i][j] == tab[i + 1][j + 1] && tab[i + 1][j + 1] == tab[i + 2][j + 2] && tab[i + 2][j + 2] == tab[i + 3][j + 3] && tab[i + 3][j + 3] == tab[i + 4][j + 4] && tab[i][j] != '+') {
				wygrana = true;
			} //na skos lewej do prawej
		}
	}

	for (int i = MAX; i > 0; i--) {
		for (int j = 0; j < MAX; j++) {
			if (tab[i][j] == tab[i - 1][j + 1] && tab[i - 1][j + 1] == tab[i - 2][j + 2] && tab[i - 2][j + 2] == tab[i - 3][j + 3] && tab[i - 3][j + 3] == tab[i - 4][j + 4] && tab[i][j] != '+') {
				wygrana = true;
			} // na skos od prawej do lewej
		}
	}

	return wygrana;
}

void Plansza::zapiszPlansze(fstream & fp)
{
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			fp << tab[i][j];
		}
		fp << endl;
	}
}
void Plansza::wczytajPlansze(fstream & fp)
{
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			fp >> tab[i][j];
		}
	}
}