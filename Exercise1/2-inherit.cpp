#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>

class student
{
protected:
	int id, math, physic;
public:
	void inputMark()
	{
		cout << "Input id: ";
		cin >> id;
		cout << "Input Math and Physic's mark: ";
		cin >> math >> physic;
	}
};

class english
{
protected:
	int eng;
public:
	void inputEnglish()
	{
		cout << "Input English's mark:";
		cin >> eng;
	}
};

class infoStudent: public student, public english
{
	int sum;
	float avg;
public:
	void disPlay()
	{
		sum = math + physic + eng;
		avg = sum / 3;
		cout << "Sum of marks = " << sum << endl;
		cout << "Avg of marks = " << avg << endl;
	}
};
int main()
{
	infoStudent info;
	info.inputMark();
	info.inputEnglish();
	info.disPlay();
	return 0;
}