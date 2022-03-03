#include <iostream>
#include <string.h>
#include <string>

#include "Operatie.h"
#include "Expresie.h"
#include "Ecuatie.h"

using namespace std;


char* valInvalida;



Operatie::Operatie()
{
	operatie = '+';
	operand1 = 0;
	operand2 = 0;
}
Operatie::Operatie(char operatie, double operand1, double operand2)
{
	this->operatie = operatie;
	this->operand1 = operand1;
	this->operand2 = operand2;
}

 int Operatie::getImpartirelaZero()
{
	return impartirelaZero;
}

void Operatie::setOperatie(char operatie)
{
	if (operatie == '+' || operatie == '-' || operatie == '*' || operatie == '/' || operatie == '^' || operatie == '#')
		this->operatie = operatie;
}
char Operatie::getOperatie()
{
	return operatie;
}
void Operatie::setOperand1(double o1)
{
	operand1 = o1;
}
double Operatie::getOperand1()
{
	return operand1;
}
void Operatie::setOperand2(double o2)
{
	operand2 = o2;
}
double Operatie::getOperand2()
{
	return operand2;
}

 void Operatie::setimpartirelaZero(int x)
{
	 if (x == 0 || x == 1)
	 {
		 impartirelaZero = x;
	 }
	 else impartirelaZero = 0;
}




//double punct(double operand1, double operand2)
//{
//	int nrCifre = 1;
//	int copie = operand2;
//	while (copie != 0)
//	{
//		copie /= 10;
//		nrCifre *= 10;
//	}
//	double rezultat = operand1 + operand2 / nrCifre;
//	return rezultat;
//}
//calcul-2 operanzi si un simbol



//operatori
//op ++
Operatie Operatie::operator++()
{
	operand1++;
	return *this;
}
Operatie Operatie::operator++(int i)
{
	Operatie copie = *this;
	operand1++;
	return copie;
}

 bool operator<=(const Operatie& o1, const Operatie& o2)
{
	return o1.operand1 < o1.operand2;
}



istream& operator>>(istream& in, Operatie& op)
{
	double o1, o2;
	char oper;
	cout << "Operand 1: ";
	cin>> o1;
	cout << "Operatie: ";
	cin >> oper;
	cout << "Operand 2: ";
	cin>> o2;
	op.setOperand1(o1);
	op.setOperatie(oper);
	op.setOperand2(o2);

	return in;
}

 ostream& operator<<(ostream& out, Operatie op)
{

	out << "Operand 1: " << op.getOperand1() << endl;
	out << "Operatie: " << op.getOperatie() << endl;
	out << "Operand 2: " << op.getOperand2() << endl;

	return out;
}





	Expresie::Expresie():pi(3.14)
	{
		expresie = nullptr;
		numere = nullptr;
		numarNumere = 0;
		operatii = nullptr;
		numarOperatii = 0;
		rezultat = 0;
		prioritateMaxima = 1;
	}
	Expresie::Expresie(char* expresie):pi(3.14)
	{
		if (expresie != nullptr)
		{
			this->expresie = new char[strlen(expresie) + 1];
			strcpy_s(this->expresie, strlen(expresie) + 1, expresie);
		}
		else
		{
			this->expresie = nullptr;
		}
		numarNumere = 0;
		numarOperatii = 0;
		if (expresie != "")
		{
			numere = new double[strlen(expresie) + 1];
			operatii = new char[strlen(expresie) + 1];
		}
		rezultat = 0;
		prioritateMaxima = 1;
	}

	//constructor de copiere
	Expresie::Expresie(const Expresie& e):pi(e.pi)
	{

		numarNumere = e.numarNumere;
		numarOperatii = e.numarOperatii;
		rezultat = e.rezultat;
		prioritateMaxima = e.prioritateMaxima;
		if (e.expresie != nullptr)
		{
			expresie = new char[strlen(e.expresie) + 1];
			strcpy_s(expresie, strlen(e.expresie) + 1, e.expresie);
		}
		if (numarNumere > 0 && e.numere != nullptr)
		{
			numere = new double[numarNumere];
			for (int i = 0; i < numarNumere; i++)
			{
				numere[i] = e.numere[i];
			}
		}
		if (numarOperatii > 0 && e.operatii != nullptr)
		{
			operatii = new char[strlen(e.operatii) + 1];
			strcpy_s(operatii, strlen(e.operatii) + 1, e.operatii);
		}
	}

	//operator egal, de atribuire
	Expresie Expresie::operator=(const Expresie& e)
	{
		if (numere != nullptr)
		{
			delete[] numere;
			numere = nullptr;
		}
		if (operatii != nullptr)
		{
			delete[] operatii;
			operatii = nullptr;
		}
		if (expresie != nullptr)
		{
			delete[] expresie;
			expresie = nullptr;
		}
		numarNumere = e.numarNumere;
		numarOperatii = e.numarOperatii;
		rezultat = e.rezultat;
		prioritateMaxima = e.prioritateMaxima;
		if (e.expresie != nullptr)
		{
			expresie = new char[strlen(e.expresie) + 1];
			strcpy_s(expresie, strlen(e.expresie) + 1, e.expresie);
		}
		if (numarNumere > 0 && e.numere != nullptr)
		{
			numere = new double[numarNumere];
			for (int i = 0; i < numarNumere; i++)
			{
				numere[i] = e.numere[i];
			}
		}
		if (numarOperatii > 0 && e.operatii != nullptr)
		{
			operatii = new char[strlen(e.operatii) + 1];
			strcpy_s(operatii, strlen(e.operatii) + 1, e.operatii);
		}
		return *this;
	}

	void Expresie::setExpresie(char* expresie)
	{
		if (expresie != nullptr)
		{
			if (this->expresie != nullptr)
			{
				delete[] this->expresie;
			}
			this->expresie = new char[strlen(expresie) + 1];
			strcpy_s(this->expresie, strlen(expresie)+1, expresie);
		}

	}
	char* Expresie::getExpresie()
	{
		return expresie;
	}

	void Expresie::setNumere(double* numere, int numarNumere)
	{
		if (numere != nullptr && numarNumere > 0)
		{
			if (this->numere != nullptr)
			{
				delete[] this->numere;
			}
			this->numere = new double[numarNumere];
			for (int i = 0; i <= numarNumere; i++)
			{
				this->numere[i] = numere[i];
			}
			this->numarNumere = numarNumere;
		}
	}

	double* Expresie::getNumere()
	{
		if (numere != nullptr && numarNumere > 0)
		{
			double* copie = new double[numarNumere];
			for (int i = 0; i < numarNumere; i++)
			{
				copie[i] = numere[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	void Expresie::setNumarNumere(int numarNumere)
	{
		if (numarNumere > 0)
		{
			this->numarNumere = numarNumere;
		}
		else
		{
			this->numarNumere = 0;
		}
	}

	void Expresie::setOperatii(char* operatii, int numarOperatii)
	{
		if (operatii != nullptr && numarOperatii > 0)
		{
			if (this->operatii != nullptr)
			{
				delete[] this->operatii;
			}
			this->operatii = new char[numarOperatii];
			for (int i = 0; i < numarOperatii; i++)
			{
				this->operatii[i] = operatii[i];
			}
			this->numarOperatii = numarOperatii;
		}
	}

	char* Expresie::getOperatii()
	{
		if (operatii != nullptr && numarOperatii > 0)
		{
			char* copie = new char[numarOperatii];
			for (int i = 0; i < numarOperatii; i++)
			{
				copie[i] = operatii[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	void Expresie::setNumarOperatii(int numarOperatii)
	{
		if (numarOperatii > 0)
		{
			this->numarOperatii = numarOperatii;
		}
		else
		{
			this->numarOperatii = 0;
		}
	}

	int Expresie::getNumaroperatii()
	{
		return numarOperatii;
	}
	int Expresie::getNumarNumere()
	{
		return numarNumere;
	}

	void Expresie::setRezultat(double rezultat)
	{
		this->rezultat = rezultat;
	}
	double Expresie::getRezultat()
	{
		return rezultat;
	}

	void Expresie::setPrioritateMaxima(int p)
	{
		if (p > 0 && p < 4)
		{
			this->prioritateMaxima = p;
		}
		else
		{
			this->prioritateMaxima = 1;
		}
	}
	int Expresie::getPrioritateMaxima()
	{
		return prioritateMaxima;
	}



	//metoda calcul
	void Expresie::prioritate()  //1-sume si scaderi   2-produs si raport   3- radical si putere
	{
		prioritateMaxima = 1;
		for (int i = 0; i < strlen(expresie); i++)
		{
			if (expresie[i] == '^' || expresie[i] == '#')
			{
				if (prioritateMaxima < 3)
				{
					prioritateMaxima = 3;
				}
			}
		}
		for (int i = 0; i < strlen(expresie); i++)
		{
			if (expresie[i] == '/' || expresie[i] == '*')
			{
				if (prioritateMaxima < 2)
				{
					prioritateMaxima = 2;
				}
			}
		}
		//return prioritateMaxima;
	}

	void Expresie::transformareNumere()   //transforma expresia data in doi vectori alocati dinamici, unul pt numere, celalalt pentru operatii
	{
		numarNumere = -1;
		numarOperatii = -1;
		string numar;
		int i = 0;
		double nr;
		while (i < strlen(expresie))
		{
			numar.clear();
			bool formareNumar = false;
			while (i < strlen(expresie) && expresie[i] != '(' && expresie[i] != ')' && expresie[i] != '[' && expresie[i] != ']'  && expresie[i] != '+' 
				&& expresie[i] != '-' && expresie[i] != '*' && expresie[i] != '/' && expresie[i] != '^' && expresie[i] != '#')
			{
				numar += expresie[i]; //adaug cifrele si punctul
				i++;
				formareNumar = true;
			}
			if (formareNumar==true)
			{
				nr = stof(numar);  //formez un numar
				numarNumere++;
				numere[numarNumere] = nr;//adaug valoarea calculata
			}
			i++;
		}

		for (i = 0; i < strlen(expresie); i++)
		{
			if ((expresie[i] < 48 || expresie[i]>57) && expresie[i] != 46)  //nu e cifra si nu e punct
			{
				numarOperatii++;
				operatii[numarOperatii] = expresie[i];
			}
		}
		numarOperatii++;
		operatii[numarOperatii] = '\0';

	}

	double Expresie::calculInteriorParanteza()
	{
		int i;
		this->prioritate();
		this->transformareNumere();
		while (prioritateMaxima != 0)
		{
			if (prioritateMaxima == 3)  //fac inati calculele cu radical si putere
			{
				for (int i = 0; i < numarOperatii; i++)
				{
					if (operatii[i] == '^' || operatii[i] == '#')
					{
						numere[i] = Operatie::calcul(numere[i], operatii[i], numere[i + 1]);
						for (int j = i + 1; j < numarNumere; j++)
						{
							numere[j] = numere[j + 1];
						}
						numarNumere--;
						for (int j = i; j < numarOperatii; j++)
						{
							operatii[j] = operatii[j + 1];
						}
						numarOperatii--;
					}
				}
				prioritateMaxima--;
			}

			if (prioritateMaxima == 2)  //fac  calculele cu * si /
			{
				for (int i = 0; i < numarOperatii; i++)
				{
					if (operatii[i] == '*' || operatii[i] == '/')
					{
						numere[i] = Operatie::calcul(numere[i], operatii[i], numere[i + 1]);
						for (int j = i + 1; j < numarNumere; j++)
						{
							numere[j] = numere[j + 1];
						}
						numarNumere--;
						for (int j = i; j < numarOperatii; j++)
						{
							operatii[j] = operatii[j + 1];
						}
						numarOperatii--;
					}
				}
				prioritateMaxima--;
			}
			if (prioritateMaxima == 1)  //fac  calculele cu + si -
			{
				while (numarOperatii > 0)
				{
					numere[0] = Operatie::calcul(numere[0], operatii[0], numere[1]);
					for (int j = 1; j < numarNumere; j++)
					{
						numere[j] = numere[j + 1];
					}
					numarNumere--;

					for (int j = 0; j < numarOperatii; j++)
					{
						operatii[j] = operatii[j + 1];
					}
					numarOperatii--;
				}
				prioritateMaxima--;
			}
		}
		rezultat = numere[0];
		return rezultat;
	}

	//operatori
	//op index
	int Expresie::operator[](int index)
	{
		if (index >= 0 && index < numarNumere)
		{
			return numere[index];
		}
		else return 0;
	}

	Expresie::operator double()
	{
		return rezultat;
	}

	Expresie::~Expresie()
	{
		if (numere != nullptr)
		{
			//delete[] numere;
			numere = nullptr;
		}
		if (operatii != nullptr)
		{
			//delete[] operatii;
			operatii = nullptr;
		}
		if (expresie != nullptr)
		{
			//delete[] expresie;
			expresie = nullptr;
		}
	}



	 istream& operator>>(istream& in, Expresie& ex)
	{
		string buffer;
		cout << "Expresie:";

		in >> buffer;
		char* buf = new char[buffer.length() + 1];
		strcpy_s(buf, buffer.length() + 1, buffer.c_str());
		ex.setExpresie(buf);
		return in;
	}

	 ostream& operator<<(ostream& out, Expresie ex)
	{
		if (ex.getExpresie() != nullptr)
		{
			out << "Expresie: " << ex.getExpresie() << endl;
		}
		else
		{
			out << "Expresie: " << endl;
		}
		out << "Numar Numere: " << ex.getNumarNumere() << endl;
		/*for (int i = 0; i < ex.getNumarNumere(); i++)
		{
			cout << ex.numere[i] << " ";
		}*/
		out << "Numar Operatii: " << ex.getNumaroperatii() << endl;
		/*for (int i = 0; i < ex.getNumaroperatii(); i++)
		{
			cout << ex.operatii[i] << " ";
		}*/
		out << "Prioritate maxima: " << ex.getPrioritateMaxima() << endl;
		out << "Rezultat: " << ex.getRezultat() << endl;
		return out;
	}





 



	Ecuatie::Ecuatie()
	{
		ecuatie = nullptr;
		numarElemente = 0;
		parantezeDrepte = false;
		parantezeRotunde = false;
		pozitiiParanteze = nullptr;
		numarParanteze = 0;
		rezultat = 0;
		okParanteze = -1;

	}
	Ecuatie::Ecuatie(char* ecuatie, int numarElemente)
	{
		this->numarElemente = numarElemente;
		this->ecuatie = new char[strlen(ecuatie) + 1];
		strcpy_s(this->ecuatie, strlen(ecuatie) + 1, ecuatie);
		parantezeDrepte = false;
		parantezeRotunde = false;
		pozitiiParanteze = nullptr;
		numarParanteze = 0;
		rezultat = 0;
		okParanteze = -1;
	}


	//constructor de copiere
	Ecuatie::Ecuatie(const Ecuatie& e)
	{
		if (e.ecuatie != nullptr && e.numarElemente>0)
		{
			ecuatie = new char[strlen(e.ecuatie) + 1];
			strcpy_s(ecuatie, strlen(e.ecuatie) + 1, e.ecuatie);
			numarElemente = e.numarElemente;
		}
		parantezeDrepte = e.parantezeDrepte;
	    parantezeRotunde=e.parantezeRotunde;
		if (e.pozitiiParanteze != nullptr && numarParanteze > 0)
		{
			pozitiiParanteze = new int[numarParanteze];
			numarParanteze = e.numarParanteze;
			for (int i = 0; i < numarParanteze; i++)
			{
				pozitiiParanteze[i] = e.pozitiiParanteze[i];
			}
		}
	}

	//op egal
	Ecuatie Ecuatie::operator=(const Ecuatie& e)
	{
		if (ecuatie != nullptr)
		{
			delete[] ecuatie;
			ecuatie = nullptr;
		}
		if (pozitiiParanteze != nullptr)
		{
			delete[] pozitiiParanteze;
			pozitiiParanteze = nullptr;
		}
		if (e.ecuatie != nullptr && e.numarElemente > 0)
		{
			ecuatie = new char[strlen(e.ecuatie) + 1];
			strcpy_s(ecuatie, strlen(e.ecuatie) + 1, e.ecuatie);
			numarElemente = e.numarElemente;
		}
		parantezeDrepte = e.parantezeDrepte;
		parantezeRotunde = e.parantezeRotunde;
		if (e.pozitiiParanteze != nullptr && numarParanteze > 0)
		{
			pozitiiParanteze = new int[numarParanteze];
			numarParanteze = e.numarParanteze;
			for (int i = 0; i < numarParanteze; i++)
			{
				pozitiiParanteze[i] = e.pozitiiParanteze[i];
			}
		}
		return *this;
	}

	void Ecuatie::setEcuatie(char* ecuatie)
	{
	
		if (ecuatie != nullptr)
		{
			if (this->ecuatie) {
				//delete[] this->ecuatie;
				this->ecuatie = nullptr;
				this->ecuatie = new char[strlen(ecuatie)];
			}
			this->numarElemente = strlen(ecuatie);
			strcpy_s(this->ecuatie, strlen(ecuatie) + 1, ecuatie);
		}
		
	}
	char* Ecuatie::getEcuatie()
	{
		return ecuatie;
	}

	bool Ecuatie::getParantezeDrepte()
	{
		return parantezeDrepte;
	}
	bool Ecuatie::getParantezeRotunde()
	{
		return parantezeRotunde;
	}
	int Ecuatie::getNumarParanteze()
	{
		return numarParanteze;
	}

	void Ecuatie::getPozitiiParanteze()     //AFISEAZA VECTORUL
	{
		for (int i = 0; i <= numarParanteze; i++)
		{
			cout << pozitiiParanteze[i] << " ";
		}
	}

	double Ecuatie::getRezultat()
	{
		return rezultat;
	}
	int Ecuatie::getokParanteze()
	{
		return okParanteze;
	}



	//metoda stergere spatii
	void Ecuatie::stergereSpatii() //fac o noua variabila de tip string, copie, aici pun cu + toate elementele care nu sunt spatiu
	{
		int k = -1;
		char* copie=new char[strlen(ecuatie)+1];
		for (int i = 0; i < strlen(ecuatie); i++)
		{
			if (ecuatie[i] != ' ')
			{
				k++;
				copie[k]= ecuatie[i];
			}
		}
		k++;
		copie[k] = '\0';
		delete[] ecuatie;
		ecuatie = new char[strlen(copie)+1];
		strcpy_s(ecuatie, strlen(copie)+1, copie);
		numarElemente = strlen(copie) + 1;
	}



	int Ecuatie::validareEcuatie()
	{
		numarParanteze = -1;
		pozitiiParanteze = new int[strlen(ecuatie)];
		int parantezaRotunda = 0, parantezaDreapta = 0;
		string paranteze;

		int ok = 1;// cod de succes, ecuatie valida
		
		for (int i = 0; i < strlen(ecuatie); i++)
		{
			if (ecuatie[i]== '(' || ecuatie[i] == ')' || ecuatie[i] == '[' || ecuatie[i] == ']')
			{
				paranteze += ecuatie[i];
				numarParanteze++;
				pozitiiParanteze[numarParanteze] = i;
			}

		}

		for (int i = 0; i < paranteze.length(); i++)
		{
			if (paranteze[i] == '(')
			{
				parantezaRotunda++;
				if (parantezaRotunda > 1)
					ok = 0;
			}

			if (paranteze[i] == '[')
			{
				parantezaDreapta++;
				if (parantezaDreapta > 1) {
					ok = 0;
				}
			}
			if (paranteze[i] == ')')
			{
				parantezaRotunda--;
				if (parantezaRotunda < 0)
					ok = 0;
			}
			if (paranteze[i] == ']')
			{
				parantezaDreapta--;
				if (parantezeRotunde < 0) {
					ok = 0;
				}
			}
		}
		if (paranteze.length() > 0)
		{
			if (paranteze[0] == ')' || paranteze[0] == ']')
				ok = 0;
		}


		for (int i = 1; i < paranteze.length(); i++)
		{
			if (paranteze[i] == ')' && paranteze[i - 1] != '(')
				ok = 0;
			if (paranteze[i] == ']' && (paranteze[i - 1] == '[' || paranteze[i-1]=='('))
				ok = 0;

		}

		if (ok==1)
		{

			for (int i = 0; i < paranteze.length(); i++)
			{

				if (paranteze[i] == '(')
				{
					parantezeRotunde = true;
				}
				if (paranteze[i] == '[')
				{
					parantezeDrepte = true;
				}
			}
		}
		okParanteze = ok;
		return ok;
	}
	

	//operatori 
	//op+
	Ecuatie Ecuatie::operator+(Ecuatie e)
	{
		Ecuatie copie = *this;
		copie.rezultat = rezultat + e.rezultat;
		return copie;
	}
	Ecuatie::operator double()
	{
		return rezultat;
	}

	bool Ecuatie::operator!()
	{
		return okParanteze;
	}



	void Ecuatie::calculator()
	{
		int ordine = 1, i, j, io, in;
		int impartire0 = 0;

		Expresie sir(ecuatie);
		string interiorP="";

		//stergereSpatii();
		//validareEcuatie();
		//sir.Ecuatie::stergereSpatii();
		if (validareEcuatie() == 1)
		{
			sir.transformareNumere();

			if (parantezeRotunde)
			{
				ordine++;
			}
			if (parantezeDrepte)
			{
				ordine++;
			}

			while (ordine > 1)
			{
				if (ordine == 3)// am ambele paranteze
				{
					i = 0;
					while (i < strlen(ecuatie))
					{
						while (i < strlen(ecuatie) && ecuatie[i] != '(')
						{
							i++;
						}
						j = i + 1;
						bool gasit = false;

						if (interiorP != "") {
							interiorP = "";
						}

						while (j < strlen(ecuatie))
						{
							interiorP += ecuatie[j];
							j++;
							if (ecuatie[j] == ')') {
								gasit = true;
								break;
							}
						}
						if (gasit) {
							char* c = new char[interiorP.length() + 1];
							strcpy_s(c, strlen(interiorP.c_str()) + 1, interiorP.c_str());
							Expresie continut(c);
							continut.transformareNumere();
							continut.calculInteriorParanteza();

							string rez = to_string(continut.getRezultat());
							string ec_veche(ecuatie);
							string interiorParanteza(c);
							interiorParanteza = '(' + interiorParanteza + ')';
							string ec_noua = ec_veche.replace(i, interiorParanteza.length(), rez);    //functie de inlocuire a parantezei

							char* ecuatieNoua = new char[ec_noua.length() + 1];
							strcpy_s(ecuatieNoua, ec_noua.length() + 1, ec_noua.c_str());

							sir.setExpresie(ecuatieNoua);
							this->setEcuatie(ecuatieNoua);
							sir.transformareNumere();

						}
						i = j + 1;
					}


					i = 0;
					while (i < strlen(ecuatie))
					{
						while (i < strlen(ecuatie) && ecuatie[i] != '[')
						{
							i++;
						}
						j = i + 1;
						bool gasit = false;

						if (interiorP != "") {
							interiorP = "";
						}

						while (j < strlen(ecuatie))
						{
							interiorP += ecuatie[j];
							j++;
							if (ecuatie[j] == ']') {
								gasit = true;
								break;
							}
						}
						if (gasit) {
							char* c = new char[interiorP.length() + 1];
							strcpy_s(c, strlen(interiorP.c_str()) + 1, interiorP.c_str());
							Expresie continut(c);
							continut.transformareNumere();
							continut.calculInteriorParanteza();

							string rez = to_string(continut.getRezultat());
							string ec_veche(ecuatie);
							string interiorParanteza(c);
							interiorParanteza = '[' + interiorParanteza + ']';
							string ec_noua = ec_veche.replace(i, interiorParanteza.length(), rez);    //functie de inlocuire a parantezei

							char* ecuatieNoua = new char[ec_noua.length() + 1];
							strcpy_s(ecuatieNoua, ec_noua.length() + 1, ec_noua.c_str());

							sir.setExpresie(ecuatieNoua);
							this->setEcuatie(ecuatieNoua);
							sir.transformareNumere();

							
						}
						i = j + 1;
					}
					ordine = 1;
				}



				if (ordine == 2)
				{
					i = 0;
					while (i < strlen(ecuatie))
					{
						while (i < strlen(ecuatie) && ecuatie[i] != '(')
						{
							i++;
						}
						j = i + 1;
						bool gasit = false;

						if (interiorP != "") {
							interiorP = "";
						}

						while (j < strlen(ecuatie))
						{
							interiorP += ecuatie[j];
							j++;
							if (ecuatie[j] == ')') {
								gasit = true;
								break;
							}
						}
						if (gasit) {
							char* c = new char[interiorP.length() + 1];
							strcpy_s(c, strlen(interiorP.c_str()) + 1, interiorP.c_str());
							Expresie continut(c);
							continut.transformareNumere();
							continut.calculInteriorParanteza();

							string rez = to_string(continut.getRezultat());
							string ec_veche(ecuatie);
							string interiorParanteza(c);
							interiorParanteza = '(' + interiorParanteza + ')';
							string ec_noua = ec_veche.replace(i, interiorParanteza.length(), rez);    //functie de inlocuire a parantezei

							char* ecuatieNoua = new char[ec_noua.length() + 1];
							strcpy_s(ecuatieNoua, ec_noua.length() + 1, ec_noua.c_str());

							sir.setExpresie(ecuatieNoua);
							this->setEcuatie(ecuatieNoua);
							sir.transformareNumere();
							ordine--;
						}
						i = j + 1;
					}
					ordine=1;				
				}
			}
			if (ordine == 1)
			{
				i = 0;
				sir.calculInteriorParanteza();
				this->rezultat = sir.getRezultat();
			}

			rezultat = sir.calculInteriorParanteza();
		}
		else
		{
			cout << "Parantezele nu sunt folosite corect"<<endl;
		}

		if (Operatie::getImpartirelaZero() == 1)
		{
			cout << "impartire la 0"<<endl;
		}
	}

	Ecuatie::~Ecuatie()
	{
		if (ecuatie != nullptr)
		{
			//delete[] ecuatie;
			ecuatie = nullptr;
		}
		if (pozitiiParanteze != nullptr)
		{
			//delete[] pozitiiParanteze;
			pozitiiParanteze = nullptr;
		}
	}

	 istream& operator>>(istream& in, Ecuatie& ec)
	{
		string buffer;
		cout << "Ecuatie:";

		in >> buffer;
		char* buf = new char[buffer.length() + 1];
		strcpy_s(buf, buffer.length() + 1, buffer.c_str());
		ec.setEcuatie(buf);
		return in;
	}

	 ostream& operator<<(ostream& out, Ecuatie ec)
	{
		if (ec.getEcuatie() != nullptr)
		{
			out << "Ecuatie: " << ec.getEcuatie() << endl;
		}
		else
		{
			out << "Ecuatie: " << endl;
		}
		out << "Paranteze drepte: " << ec.getParantezeDrepte();
		out << "Paranteze rotunde: " << ec.getParantezeRotunde();
		out << "Parantezele sunt asezate corect: " << ec.getokParanteze();
		out << "Rezultat: " << ec.getRezultat();

		return out;
	}



double stergereZeroParteZecimala(double x)
{
	string nr = to_string(x);
	nr.erase(nr.find_last_not_of('0') + 1, string::npos);
	double nou_x = stof(nr);
	return nou_x;
}


int Operatie::impartirelaZero = 0;
int main()
{
	cout.precision(5);
	char s[100];
	cin.getline(s, 100);
	int dim = 0;
	double x;

	while (strcmp(s, "exit") != 0)
	{
		dim = strlen(s);
		Ecuatie ec(s, dim);
		ec.stergereSpatii();
		ec.calculator();
		if (Operatie::getImpartirelaZero() != 1 && ec.getokParanteze() != 0)
		{
			x = ec.getRezultat();
			cout << fixed << x << endl;
		}
		cin.getline(s, 100);
		Operatie::setimpartirelaZero(0);
	}
	

}