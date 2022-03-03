#include <iostream>
#include <string.h>
#include <string>


using namespace std;


class Expresie    //calculez continutul parantezelor, nu va contine paranteze, //pot avea un double*pentru nuemerele din ecuatie
{
private:
	char* expresie;
	double* numere;
	int numarNumere;
	char* operatii;
	int numarOperatii;
	double rezultat;
	int prioritateMaxima;
	const int pi;

public:

	Expresie();
	Expresie(char* expresie);

	//constructor de copiere
	Expresie(const Expresie& e);

	//operator egal, de atribuire
	Expresie operator=(const Expresie& e);

	void setExpresie(char* expresie);
	char* getExpresie();

	void setNumere(double* numere, int numarNumere);

	double* getNumere();

	void setNumarNumere(int numarNumere);

	void setOperatii(char* operatii, int numarOperatii);

	char* getOperatii();

	void setNumarOperatii(int numarOperatii);

	int getNumaroperatii();
	int getNumarNumere();

	void setRezultat(double rezultat);
	double getRezultat();

	void setPrioritateMaxima(int p);
	int getPrioritateMaxima();



	//metoda calcul
	void prioritate();

	void transformareNumere();

	double calculInteriorParanteza();

	//operatori
	//op index
	int operator[](int index);
	

	operator double();

	~Expresie();


	friend istream& operator>>(istream& in, Expresie& ex);

	friend ostream& operator<<(ostream& out, Expresie ex);


};
