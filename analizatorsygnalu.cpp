#include "analizatorsygnalu.hpp"

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
