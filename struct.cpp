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
	
	void append(String &other)
	{
		size_t size_other = strlen(other.str);
		char *str_ap = new char[this->size + other.size+1];
		strcpy_s(str_ap,this->size+1, this->str);
		strcpy_s(str_ap+ size, other.size+1,other.str);
		delete [] this->str;
		this->str = str_ap;
		this->size += other.size ;
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
