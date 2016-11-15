#include <stdio.h>
#include <iostream>
using namespace std;

typedef enum {
	monday, tuesday, wednesday, thursday, friday, saturday, sunday
} days;

int main()
{
	cout << days(3) << endl;
	cout << tuesday << endl;
	cout << "He he" << endl;
	return 0;
}