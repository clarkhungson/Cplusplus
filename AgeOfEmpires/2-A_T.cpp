#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>

class Archers_T
{
	char *name;
	int blood;
	int streng;
public:
	Archers_T()
	{
		strcpy(name, "T");
		blood = 35;
		streng = 3;
	}
	void attack()
	{
		//A.blood -= streng;
	}
	void show()
	{
		cout << "---------------------------" << endl;
		cout << "This is a T" << endl;
		cout << "Name: " << name << endl;
		cout << "Blood: " << blood << endl;
		cout << "Streng " << streng << endl;
		cout << "---------------------------" << endl;
	}

	int getBlood()
	{
		return blood;
	}

	void setBlood(int blood)
	{
		this -> blood = blood;
	}
};

class Archers_A
{
	char *name;
	int blood;
	int streng;
public:
	Archers_A()
	{
		strcpy(name, "A");
		blood = 40;
		streng = 4;
	}
	void attack(Archers_T &T)
	{
		T.setBlood(T.getBlood() - streng);
	}
	void show()
	{
		cout << "---------------------------" << endl;
		cout << "This is an A" << endl;
		cout << "Name: " << name << endl;
		cout << "Blood: " << blood << endl;
		cout << "Streng " << streng << endl;
		cout << "---------------------------" << endl;
	}

	int getBlood()
	{
		return blood;
	}

	void setBlood(int blood)
	{
		this -> blood = blood;
	}
};

int main()
{
	// Create a T and an A
	Archers_T T;
	Archers_A A;

	// Show T status
	T.show();

	// A attack T, show T status again
	A.attack(T);
	T.show();
	return 0;
}