#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>

class prime
{
	int a, k, i;
public:
	prime(int x)
	{
		a = x;
	}
	void calculate()
	{
		k = 1;
		for (i = 2; i < a/2; i++)
		{
			if (a % i == 0)
			{
				k = 0;
				break;
			}
			else
				k = 1;
		}
	}
	void show()
	{
		cout << a << endl;
		cout << k << endl;
		if (k == 1) 
			cout << "Prime" << endl;
		else
			cout << "Not prime" << endl;
	}
};

int main(int argc, char *argv[])
{
	int N;
	N = atoi(argv[1]);
	prime n(N);
	n.calculate();
	n.show();
}