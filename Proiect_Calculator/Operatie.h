#include <iostream>
#include <string.h>
#include <string>


using namespace std;

class Operatie    //radica, punct, putere
{
private:
	char operatie;  //., #, ^
	double operand1;
	double operand2;
	static int impartirelaZero;

public:
	Operatie();
	Operatie(char operatie, double operand1, double operand2);
	static int getImpartirelaZero();
	void setOperatie(char operatie);
	char getOperatie();
	void setOperand1(double o1);
	double getOperand1();
	void setOperand2(double o2);
	double getOperand2();
	int getImpartireLaZero();
	static void setimpartirelaZero(int x);
	static double putere(double operand1, double operand2)
	{
		{
			if (operand1 == 0)
			{
				return 0;
			}
			if (operand2 == 0)
			{
				return 1;
			}
			if (operand2 < 0)
			{
				return 1 / putere(operand1, -operand2);  //rastorn fractia si pun la putere pozitiva
			}
			else if (operand2 > 0 && operand2 < 1)
			{
				return radical(operand1, 1 / operand2);
			}
			else if ((int)operand2 % 2 == 0)
			{
				double jumatate = putere(operand1, operand2 / 2);
				return jumatate * jumatate;
			}
			else
			{
				return operand1 * putere(operand1, operand2 - 1);
			}
		}
	}
	static double radical(double operand1, double operand2)
	{
		const int k = 6;
		double x[k] = { 1 };
		for (int i = 0; i < k - 1; i++)
		{
			x[i + 1] = (1.0 / operand2) * ((operand2 - 1) * x[i] + operand1 / putere(x[i], operand2 - 1));
		}
		return x[k - 1];
	}
	double punct(double operand1, double operand2);
	static double calcul(double operand1, char simbol, double operand2)
	{
		{
			if (simbol == '+')
			{
				return operand1 + operand2;
			}
			if (simbol == '-')
			{
				return operand1 - operand2;
			}
			if (simbol == '*')
			{
				return operand1 * operand2;
			}
			if (simbol == '/')
			{
				if (operand2 != 0)
				{
					return operand1 / operand2;
				}
				else
				{
					Operatie::setimpartirelaZero(1);
					return 0;
				}
			}
			if (simbol == '^')
			{
				return putere(operand1, operand2);
			}
			if (simbol == '#')
			{
				return radical(operand1, operand2);
			}
		}
	}

	//operatori
	//op ++
	Operatie operator++();
	Operatie operator++(int i);

	friend  istream& operator>>(istream& in, Operatie& op);
	friend  ostream& operator<<(ostream& out, Operatie op);
	friend bool operator<=(const Operatie& o1, const Operatie& o2);
}; 
