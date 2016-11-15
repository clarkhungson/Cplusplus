#include <stdio.h>
#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <vector>
//#include "4-building.cpp"

typedef struct {
	const char * name;
	int blood;
	int damage;
	int speed;
	int armor;
} Unit_struct;

Unit_struct unit_database[] = {
	{"Archers_A", 45, 5, 1, 0},
	{"Archers_T", 35, 4, 1, 0},
	{"Cavalry_C", 150, 8, 2, 0},
	{"Conjurer", 25, 0, 1, 0}
};



class Unit
{
	char *name;
	int blood;
	int damage;
	int speed;
	bool alive;
	int armor;
public:
	const static int id = 0;
	static int count;
	Unit()
	{
		this -> name = new char(10);
		strcpy(this -> name, "");
		this -> blood = 0;
		this -> damage = 0;
		this -> speed = 0;
		this -> alive = true;
		this -> armor = 0;
		count++;
	}

	Unit(const char * name, int blood, int damage, int speed, int armor)
	{
		this -> name = new char(10);
		strcpy(this -> name, name);
		this -> blood = blood;
		this -> damage = damage;
		this -> speed = speed;
		this -> speed = true;
		this -> armor = armor;
		count++;
	}



	void show()
	{
		cout << "---------------------------" << endl;
		cout << "This is a " << name << endl;
		cout << "Name: " << name << endl;
		cout << "Blood: " << blood << endl;
		cout << "Damage: " << damage << endl;
		cout << "Speed: " << speed << endl;
		cout << "Armor: " << armor << endl;
		cout << "---------------------------" << endl;
	}

	void attack(Unit &T)
	{
		T.setBlood(T.getBlood() - damage);
	}

	char *getName()
	{
		return name;
	}

	void setName(const char * name)
	{
		strcpy(this -> name, name);
	}

	int getBlood()
	{
		return blood;
	}

	void setBlood(int blood)
	{
		this -> blood = blood;
	}

	int getDamage()
	{
		return damage;
	}

	void setDamage(int damage)
	{
		this -> damage = damage;
	}

	int getSpeed()
	{
		return speed;
	}

	void setSpeed(int speed)
	{
		this -> speed = speed;
	}

	int getArmor()
	{
		return armor;
	}

	void setArmor(int armor)
	{
		this -> armor = armor;
	}

	bool isAlive()
	{
		if (blood > 0) return true;
		else return false;
	}

	virtual void upgrade() {}

	virtual void reset_Blood(int id)
	{

	}

	static Unit *factory_Unit(int id);
};

int Unit::count = 0;

class Archers: public Unit
{
public:
	Archers(const char * name, int blood, int damage, int speed, int armor) : Unit(name, blood, damage, speed, armor) {}
	void upgrade()
	{
		setArmor(getArmor() + 2);
		cout << "***";
	}
	
};

class Cavalry: public Unit
{
public:
	Cavalry(const char * name, int blood, int damage, int speed, int armor) : Unit(name, blood, damage, speed, armor) {}
};

class Archers_A: public Archers
{
	const static int id = 0;
public:
	Archers_A() : Archers(unit_database[id].name, unit_database[id].blood, unit_database[id].damage, unit_database[id].speed, unit_database[id].armor) {}
	void reset_Blood()
	{
		setBlood(45);
	}

};

class Archers_T: public Archers
{
	const static int id = 1;
public:
	Archers_T() : Archers(unit_database[id].name, unit_database[id].blood, unit_database[id].damage, unit_database[id].speed, unit_database[id].armor) {}
	void reset_Blood()
	{
		Archers_T();
	}
};

class Cavalry_C: public Cavalry
{
	const static int id = 2;
public:
	Cavalry_C(): Cavalry(unit_database[id].name, unit_database[id].blood, unit_database[id].damage, unit_database[id].speed, unit_database[id].armor) {}
};

class Conjurer: public Unit
{
	const static int id = 3;
public:
	//Conjurer(): Unit("Conjurer", 25, 0, 1) {}
	Conjurer(): Unit(unit_database[id].name, unit_database[id].blood, unit_database[id].damage, unit_database[id].speed, unit_database[id].armor) {}
	void respawnBlood(Unit &unit)
	{
		while (unit.getBlood() < unit_database[unit.id].blood)
		{
			unit.setBlood(unit.getBlood() + 2);
			if (unit.getBlood() > unit_database[unit.id].blood)
				unit.setBlood(unit_database[unit.id].blood);
			unit.show();
			sleep(1);
		}		
	}
};

class Building
{
	char * name;
	int blood;
	int price;
	vector<Unit *> vec;

public:
	Building()
	{
		name = new char[10];
		strcpy(name, "");
		blood = 0;
		price = 0;
	}
	Building(const char * name, int blood, int price)
	{
		this -> name = new char[10];
		strcpy(this -> name, name);
		this -> blood = blood;
		this -> price = price;
	}

	void attach(Unit *unit)
	{
		vec.push_back(unit);
		cout << "attach" << endl;
	}
	void notify()
	{
		for (vector<Unit *>::iterator v = vec.begin(); v != vec.end(); v++)
		{
			(*v) -> upgrade();
			cout << "notify" << endl;

		}
		cout << "---" << endl;;
	}
};

//int Conjurer::id = 3;

int main()
{
	// Archers_A A;
	// A.show();

	// Archers_T T;
	// T.show();

	// Cavalry_C C;
	// C.show();

	// Conjurer conj;
	// conj.show();

	//Building building;

	Building building;

	Unit *A = Unit::factory_Unit(0);
	building.attach(A);
	A -> show();
	building.notify();
	A -> show();

	Unit *T = Unit::factory_Unit(1);
	T -> show();

	Unit *C = Unit::factory_Unit(2);
	C -> show();

	Unit *conj = Unit::factory_Unit(3);
	conj -> show();

	cout << Unit::count << endl;


	// The battle between A and T
	// while (A.isAlive() && T.isAlive())
	// {
	// 	A.attack(T);
	// 	T.attack(A);
	// 	T.show();
	// 	A.show();
	// 	sleep(1);
	// }

	// if (A.isAlive())
	// {
	// 	cout << "A won" << endl;
	// }
	// else 
	// 	cout << "A lost" << endl;

	// A.show();
	// A.reset_Blood();
	// A.show();

	// The conjurer help A respawn his blood
	// T.attack(A);
	// T.attack(A);
	// T.attack(A);
	// A.show();
	// conj.respawnBlood(A);
	//A.show();


	return 0;
}

Unit *Unit::factory_Unit(int id)
{
	if (id == 0)
			return new Archers_A();
		else if (id == 1)
			return new Archers_T();
		else if (id == 2)
			return new Cavalry_C();
		else if (id == 3)
			return new Conjurer();
}

