#include <stdio.h>
#include <iostream>
#include "a.cpp"
using namespace std;
int main(){
	extern int a;
	cout << a << endl;
	return 0;
}
