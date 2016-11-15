#include <stdio.h>
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <string.h>

class CString
{
private:
	char* m_str;
public:
	CString(char *s = NULL)
	{
		if(s == 0)
		{
			m_str = strdup("");
		}
		else
		{
			m_str = strdup(s);
		}
	}
	~CString()
	{
		if(m_str != NULL)
		{
			cout << "deleting ..." << endl;
			delete [] m_str;
		}
	}

	CString & operator = (const CString & s)
	{
		delete this -> m_str;
		this -> m_str = strdup(s.m_str);
		return *this;
	}

	CString & operator + (const CString & s)
	{
		char * nStr = new char[strlen(s.m_str) + strlen(this -> m_str) + 1];
		strcpy(nStr, this -> m_str);
		strcat(nStr, s.m_str);
		delete this -> m_str;
		this -> m_str = nStr;
		return *this;
	}

	void print()
	{
		cout << this -> m_str << endl;
	}
};

int main()
{
	CString str1 = "vncoding";
	CString str2 = ".net";
	str1.print();
	CString str;
	str = str1 + str2;
	str.print();
	str1 = str2;
	str1.print();
	return 0;
}