#include <stdio.h>
#include <iostream>
using namespace std;
#include <map>


int main()
{
	map<string, string> Employees;

	Employees["a"] = "Mike C";
	Employees["b"] = "Charlie M";
	Employees["c"] = "David D";

	Employees.insert(pair<string, string>("d", "Clark"));
	Employees.insert(map<string, string>::value_type("e", "Nana"));
	Employees.insert(make_pair("f", "Lois"));

	cout << "Map size: " << Employees.size() << endl;

	for (map<string, string>::iterator ii = Employees.begin(); ii != Employees.end(); ++ii)
	{
		cout << (*ii).first << ": " << (*ii).second << endl;
	}
	return 0;
}