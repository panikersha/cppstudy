#include "pch.h"
#include <iostream>

using namespace std;


char *resize(const char *str, unsigned size, unsigned new_size)
{
	char * new_m = new char[new_size];
	for (int i = 0; i < new_size && i < size; i++)
	{
		new_m[i] = str[i];
		
 	}

	delete [] str;
	str = 0;

	return new_m;
}

int main()
{
	char *s = new char[sizeof("Stepik.org")]{ "Stepik.org" };
	cout << s<<endl;
	char * new_S = resize(s, 10, 5);
	cout << s<<endl;
	cout << new_S;
	delete [] new_S;
	new_S = 0;
	return 0;
}
