#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

struct Probka {
	double t;
	double x;
};

vector<Probka> wczytaj(string nazwa) {
	vector<Probka> dane;
	ifstream plik("sygnal.csv");
	string linia;
	while (getline(plik, linia))
	{
		stringstream ss(linia);
		double x1, x2;
		ss >> x1;
		ss.ignore();
		ss >> x2;
		Probka probka = { x1,x2 };
		dane.push_back(probka);
	}
	dane.erase(dane.begin());
	plik.close();
	return dane;
}

void wypisz(vector<Probka> dane) {
	for (int i = 0; i < dane.size(); i++)
		cout << dane[i].t << " " << dane[i].x << endl;
}

void zapisz(string nazwa , vector<Probka> dane) {
	ofstream plik(nazwa);
	plik << "t,x\n";
	for (int i = 0; i < dane.size(); i++) {
		plik << dane[i].t << "," << dane[i].x << "\n";
	}

	plik.close();
}

double obliczDlugosc(vector<Probka> dane) {
	double t1, t2;
	t1 = dane[0].t;
	t2 = dane[0].t;
	for (int i = 0; i < dane.size(); i++) {
		if (dane[i].t < t1)
			t1 = dane[i].t;
		if (dane[i].t > t2)
			t2 = dane[i].t;
	}
	return t2 - t1;
}

double obliczMin(vector<Probka> dane) {
	double min = dane[0].x;
	for (int i = 0; i < dane.size(); i++) {
		if (dane[i].x < min)
			min = dane[i].x;
	}
	return min;
}

double obliczMax(vector<Probka> dane) {
	double max = dane[0].x;
	for (int i = 0; i < dane.size(); i++) {
		if (dane[i].x > max)
			max = dane[i].x;
	}
	return max;
}

double obliczSrednia(vector<Probka> dane) {
	double sr = 0;
	for (int i = 0; i < dane.size(); i++)
		sr += dane[i].x;
	sr = sr / dane.size();
	return sr;
}

double calkuj(vector<Probka> dane) {
	double calka = 0;
	for (int i = 0; i < dane.size() - 1; i++) {
		double dt = dane[i + 1].t - dane[i].t;
		double dpole = dane[i].x + dane[i + 1].x;
		dpole = dpole * dt / 2;
		calka += dpole;
	}
	return calka;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
    {
		throw runtime_error("sygnal.csv");
        return -1;
	}
    cout << argv[1] << endl;
	string sygnal = argv[1];
	cout << "Odczytuje plik : " << sygnal << endl;

	vector<Probka> dane = wczytaj(sygnal);

	wypisz(dane);

	zapisz("out.csv", dane);

	cout << "Dlugosc probki: " << obliczDlugosc(dane) << endl;

	cout << "Wartosc min: " << obliczMin(dane) << endl;

	cout << "Wartosc max: " << obliczMax(dane) << endl;

	cout << "Wartosc srednia: " << obliczSrednia(dane) << endl;

	cout << "Calka sygnalu: " << calkuj(dane) << endl;

    return 0;
}
