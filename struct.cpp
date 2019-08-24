#include "pch.h"
#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

using namespace std;



struct String {

	String(const char *str = "")
	{
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy(this->str, str);

	}

	size_t size;
	char *str;
};


int main()
{
	String p ("Hello\0");
	cout << p.size << " " << p.str;

	return 0;
}
