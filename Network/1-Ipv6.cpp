#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
using namespace std;

#define int_16 unsigned short

class Clk_IPv6Address
{
	int_16 hextex[8];
	unsigned int fPrefixLengthBits;
public:
	Clk_IPv6Address()
	{
		for (int i = 0; i < 8; i++)
			this -> hextex[i] = 0;
	}

	Clk_IPv6Address(const char *pString)
	{
		fPrefixLengthBits = 0;
		int hextex_id = 0;
		int_16 buffer = 0;
		for (int i = 0; i < strlen(pString); i++)
		{
			if (pString[i] != ':')
				{
					buffer = buffer * 16 + Hex2Int(pString[i]);
				}

			else
			{
				hextex[hextex_id] = buffer;
				hextex_id++;
				buffer = 0;
			}
			hextex[7] = buffer;
			
		}
	}

	Clk_IPv6Address(int_16 *ipv6)
	{
		for (int i = 0; i < 8; i++)
			this -> hextex[i] = ipv6[i];
		fPrefixLengthBits = 0;
	}

	void print_IPv6()
	{
		printf("%x:%x:%x:%x:%x:%x:%x:%x \n", hextex[0], hextex[1], hextex[2], hextex[3], hextex[4], hextex[5], hextex[6], hextex[7]);
	}

	int Hex2Int(char element)
	{
		if (isdigit(element))
			return (element - '0');
		else if (isupper(element))
			return (element - 'A' + 10);
		else
			return (element - 'a' + 10);
	}
};
const Clk_IPv6Address kIPv6UnspecifiedIPv6Address(":");

int main()
{
	int_16 ipv6_1[] = {0x2001, 0x0000, 0x3238, 0xDFE1, 0x30, 0x0000, 0x0000, 0xFEFB};
	Clk_IPv6Address ip_1(ipv6_1);
	ip_1.print_IPv6();
	Clk_IPv6Address ip_2("2001:0000:3238:DFE1:0030:0000:0000:FEFB");
	ip_2.print_IPv6();
	return 0;
}

