#include <stdio.h>
#include <iostream>
using namespace std;

typedef enum {
	monday, tuesday, wednesday, thursday, friday, saturday, sunday
} days;

// Clark was here! :P
int main()
{
	cout << days(3) << endl;
	cout << tuesday << endl;
	cout << "He he" << endl;
	return 0;
}
