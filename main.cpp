#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

/*struct Probka {
	double t;
	double x;
};*/

class Probka {
private:
	double t, x;
public:
	Probka(void);
	Probka(double x, double t);

	double getX() {
		return this->x;
	}

	double getT() {
		return this->t;
	}
};

Probka::Probka(void) {
	x = 0;
	t = 0;
}

Probka::Probka(double x, double t) {
	this->x = x;
	this->t = t;
}


class Sygnal{
private:
	vector<Probka> dane;
public:
	Sygnal(void);
	Sygnal(vector<Probka> dane);



	vector<Probka> getDane() {
		return this->dane;
	}

	friend class AnalizatorSygnalu;
	friend class SygnalLoader;
};

Sygnal::Sygnal(void) {

}

Sygnal::Sygnal(vector<Probka> dane) {
	this->dane = dane;
}

class SygnalLoader {

public:
	SygnalLoader(void);

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
			Probka probka(x2, x1);
			dane.push_back(probka);
		}
		dane.erase(dane.begin());
		plik.close();
		return dane;
	}

	void zapisz(string nazwa, Sygnal & s) {
		ofstream plik("sygnal.csv");
		plik << "t,x\n";
		for (int i = 0; i < s.dane.size(); i++) {
			plik << s.dane[i].getT() << "," << s.dane[i].getX() << "\n";
		}

		plik.close();
	}

};

SygnalLoader::SygnalLoader(void) {

}

class AnalizatorSygnalu {

public:

	AnalizatorSygnalu(void);

	double obliczDlugosc(Sygnal & s) {
		double t1, t2;
		t1 = s.dane[0].getT();
		t2 = s.dane[0].getT();
		for (int i = 0; i < s.dane.size(); i++) {
			if (s.dane[i].getT() < t1)
				t1 = s.dane[i].getT();
			if (s.dane[i].getT() > t2)
				t2 = s.dane[i].getT();
		}
		return t2 - t1;
	}

	void wypisz(Sygnal & s) {

		for (int i = 0; i < s.dane.size(); i++)
			cout << s.dane[i].getT() << " " << s.dane[i].getX() << endl;
	}



	double obliczMin(Sygnal & s) {
		double min = s.dane[0].getX();
		for (int i = 0; i < s.dane.size(); i++) {
			if (s.dane[i].getX() < min)
				min = s.dane[i].getX();
		}
		return min;
	}

	double obliczMax(Sygnal & s) {
		double max = s.dane[0].getX();
		for (int i = 0; i < s.dane.size(); i++) {
			if (s.dane[i].getX() > max)
				max = s.dane[i].getX();
		}
		return max;
	}

	double obliczSrednia(Sygnal & s) {
		double sr = 0;
		for (int i = 0; i < s.dane.size(); i++)
			sr += s.dane[i].getX();
		sr = sr / s.dane.size();
		return sr;
	}

	double calkuj(Sygnal & s) {
		double calka = 0;
		for (int i = 0; i < s.dane.size() - 1; i++) {
			double dt = s.dane[i + 1].getT() - s.dane[i].getT();
			double dpole = s.dane[i].getX() + s.dane[i + 1].getX();
			dpole = dpole * dt / 2;
			calka += dpole;
		}
		return calka;
	}
};

AnalizatorSygnalu::AnalizatorSygnalu() {

}



int main(int argc, char* argv[])
{
	if (argc != 2) {
		throw runtime_error("sygnal.csv");
	}

	string nazwa_pliku = argv[1];
	cout << "Odczytuje plik : " << nazwa_pliku << endl;

	SygnalLoader sl;

	AnalizatorSygnalu al;

	Sygnal s(sl.wczytaj(nazwa_pliku));

	al.wypisz(s);

	sl.zapisz("out.csv", s);

	cout << "Dlugosc probki: " << al.obliczDlugosc(s) << endl;

	cout << "Wartosc min: " << al.obliczMin(s) << endl;

	cout << "Wartosc max: " << al.obliczMax(s) << endl;

	cout << "Wartosc srednia: " << al.obliczSrednia(s) << endl;

	cout << "Calka sygnalu: " << al.calkuj(s) << endl;

	return 0;
}
