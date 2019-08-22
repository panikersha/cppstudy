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

char *getline()
{
	char ch = '\0';
	int size = 1;
	char * row = new char[size];
	*row = ch;
	
	while (cin.get(ch) && ch != '\0' && ch != cin.eof() && ch != '\n')
	{
		
		char * temp = new char[size+1];
		int i = 0;
		for (i = 0; i < size-1; i++)
		{
			temp[i] = row[i];
		}
		size++;
		temp[i] = ch;
		temp[i + 1] = '\0';
		delete [] row;
		row = 0;
		row = temp;
	}
	return row;
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
	
	
	char * row;
	row = getline(); 
	cout << row << endl;
	delete [] row;
	row = 0;
	
	return 0;
}
