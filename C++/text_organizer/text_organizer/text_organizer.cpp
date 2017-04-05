#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string processLine(string line, char znak) {
	int count = 0;
	for (int i = 0; i < line.length(); i++)
	{
		if (isspace(line[i]))
		{
			line[i] = line[i + 1];
		}
		if (line[i] == znak)
		{
			line[i] = '\n';
			count++;
		}
	}
	cout << "Znaleziono " << count << " rekordow" << endl;
	return line;
}
void saveFile(string output)
{
	ofstream out;
	string sciezka;
	cout << "Podaj sciezke pliku do zapisu: ";
	cin >> sciezka;
	out.open(sciezka, ios::out);
	out << output;
	out.close();
	cout << endl << "Plik zapisano w "<< sciezka << endl;
}
int main()
{
	char znak;
	string line;
	string output;
	int *wsk;
	string sciezka;
	fstream file;

	cout << "Podaj sciezke pliku zrodlowego: ";
	cin >> sciezka;
	file.open(sciezka , ios::in);

	cout << "Podaj znak po ktorym mam wstawic CR-LF" << endl;
	cout << "Znak: ";
	cin >> znak;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			output += processLine(line, znak);
		}
		file.close();
	}
	else {
		cout << "Nie mozna odnalezc pliku." << endl;
	}

	saveFile(output);
	system("pause");
	return 0;
}