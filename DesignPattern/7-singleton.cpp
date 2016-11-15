#include <stdio.h>
#include <iostream>
using namespace std;

class GlobalClass
{
	int m_value;
	static GlobalClass *s_instance;
	GlobalClass(int v = 0)
	{
		m_value = v;
	}
public:
	int get_value()
	{
		return m_value;
	}

	void set_value(int v)
	{
		m_value = v;
	}
	static GlobalClass *instance()
	{
		if (!s_instance)
		{
			s_instance = new GlobalClass;
		}
		return s_instance;
	}
};

GlobalClass *GlobalClass::s_instance = NULL;

void foo(void)
{
	GlobalClass::instance() -> set_value(1);
	cout << "foo: global_ptr is " << GlobalClass::instance() -> get_value() << endl;
}

void bar(void)
{
	GlobalClass::instance() -> set_value(2);
	cout << "foo: global_ptr is " << GlobalClass::instance() -> get_value() << endl;
}

int main()
{	
	foo();
	bar();
	return 0;
}

// #include <stdio.h>
// #include <iostream>
// using namespace std;
// #include <vector>

// class GlobalClass
// {
// 	int m_value;
// public:
// 	GlobalClass(int v = 0)
// 	{
// 		m_value = v;
// 	}
// 	int get_value()
// 	{
// 		return m_value;
// 	}

// 	void set_value(int v)
// 	{
// 		m_value = v;
// 	}
// };

// GlobalClass *global_ptr = 0;

// void foo(void)
// {
// 	if (!global_ptr)
// 		global_ptr = new GlobalClass;
// 	global_ptr -> set_value(1);
// 	cout << "foo: global_ptr is " << global_ptr -> get_value() << '\n';
// }

// void bar(void)
// {
// 	if (!global_ptr)
// 		global_ptr = new GlobalClass;
// 	global_ptr -> set_value(2);
// 	cout << "bar: global_ptr is " << global_ptr -> get_value() << '\n';
// }

// int main()
// {	
// 	if (!global_ptr)
// 		global_ptr = new GlobalClass;
// 	cout << "main: global_ptr is " << global_ptr -> get_value() << '\n';
// 	foo();
// 	bar();
// 	return 0;
// }