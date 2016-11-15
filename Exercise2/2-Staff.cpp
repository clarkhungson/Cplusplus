#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>

class CPerson
{
private:
	char *name;
	int age;
public:
	CPerson()
	{
		name = NULL;
		age = 0;
	}
	CPerson(char *str_name, int age)
	{
		name = strdup(str_name);
		this -> age = age;
	}
	~CPerson()
	{
		if(name != NULL) delete name;
	}
	void show_person_info()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
	void setName(char *name)
	{
		this -> name = strdup(name);
	}
	void setAge(int age)
	{
		this -> age = age;
	}
	char *getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
};

class CStaff : public CPerson
{
private:
	char *code;
public:
	CStaff() : CPerson()
	{
		code = NULL;
	}
	CStaff(char *name, int age, char *code) : CPerson(name, age)
	{
		this -> code = strdup(code);
	}
	~CStaff()
	{
		cout << "delete ..." << getName() << endl;
		if(code != NULL) delete code;	
	}
	void show_staff_info()
	{
		cout << "Staff information" << endl;
		show_person_info();
		cout << "Code: " << code << endl;
	}
};

int main()
{
	CStaff staff("Clark", 23, "21");
	staff.show_staff_info();
}