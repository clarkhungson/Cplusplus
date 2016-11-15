#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Observer
{
	int blood;
public:
	Observer()
	{
		blood = 0;
	}
	void update()
	{
		blood = blood + 2;
		cout << "___" << endl;
	}
	int getBlood()
	{
		return blood;
	}
};

class Subject
{
	vector<Observer *> vec_obs;
public:
	Subject()
	{
	}
	void attach(Observer *obs)
	{
		vec_obs.push_back(obs);
	}
	void notify()
	{
		for (vector<Observer *>::iterator v = vec_obs.begin(); v != vec_obs.end(); v++)
		{
			(*v)->update();
			cout << "***" << endl;
		}
	}
};



int main()
{
	Subject sub;
	Observer *obs = new Observer;
	sub.attach(obs);
	cout << "Before: " << obs->getBlood() << endl;
	sub.notify();
	cout << "After: " << obs->getBlood() << endl;
	return 0;
}