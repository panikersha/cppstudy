
#include "pch.h"
#include <iostream>

using namespace std;

bool contains(int * p, int * q, int value)
{
	for (; p != q; ++p)
		if (*p == value) return true;
	return false;
}


int main()
{
	int res = 0;
	int p[5] = { 1,2,3,4,5 };

	 cout << contains(p,p+5,9);
	return 0;
}
