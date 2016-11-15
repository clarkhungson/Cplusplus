// Class for archers with inherit

#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>

class Archers
{
	char *name;
	int blood;
	int streng;
public:

	Archers(const char * name, int blood, int streng)
	{
		this -> name = new char(10);
		strcpy(this -> name, name);
		this -> blood = blood;
		this -> streng = streng;
	}

	void show()
	{
		cout << "---------------------------" << endl;
		cout << "This is a " << name << endl;
		cout << "Name: " << name << endl;
		cout << "Blood: " << blood << endl;
		cout << "Streng " << streng << endl;
		cout << "---------------------------" << endl;
	}

	void attack(Archers &T)
	{
		T.setBlood(T.getBlood() - streng);
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




class Archers_T: public Archers
{
public:
	Archers_T() : Archers("T", 35, 3) {}
	
	
};

class Archers_A: public Archers
{
public:
	Archers_A() : Archers("A", 40, 4) {}
};

int main()
{
	// Create a T and an A
	Archers_A A;
	A.show();
	Archers_T T;
	T.show();

	// A attack T, show T status again
	A.attack(T);
	T.show();

	// T attack A, show A status again
	T.attack(A);
	A.show();

	return 0;
}