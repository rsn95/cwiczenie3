#include "sygnalloader.hpp"

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
