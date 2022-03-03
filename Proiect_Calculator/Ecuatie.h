#include <iostream>
#include <string.h>
#include <string>



using namespace std;


class Ecuatie    //primesc intreaga ecuatie  validare, stergere spatii
{
private:
	char* ecuatie;
	int numarElemente;
	bool parantezeDrepte;
	bool parantezeRotunde;
	int* pozitiiParanteze;
	int numarParanteze;
	double rezultat;
	int okParanteze;

public:

	Ecuatie();
	Ecuatie(char* ecuatie, int numarElemente);


	//constructor de copiere
	Ecuatie(const Ecuatie& e);

	//op egal
	Ecuatie operator=(const Ecuatie& e);

	void setEcuatie(char* ecuatie);
	char* getEcuatie();

	bool getParantezeDrepte();
	bool getParantezeRotunde();
	int getNumarParanteze();

	void getPozitiiParanteze();

	double getRezultat();
	int getokParanteze();



	//metoda stergere spatii
	void stergereSpatii();



	int validareEcuatie();
	

	//operatori 
	//op+
	Ecuatie operator+(Ecuatie e);
	operator double();

	bool operator!();



	void calculator();

	~Ecuatie();

	friend istream& operator>>(istream& in, Ecuatie& ec);

	friend ostream& operator<<(ostream& out, Ecuatie ec);
};