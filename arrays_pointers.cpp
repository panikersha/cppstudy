
#include "pch.h"
#include <iostream>

using namespace std;

int max_element(int * m, int size)
{
	int max = *m;
	for (int i = 0; i < size; i++)
		if (m[i] > max) max = m[i];
	return max;
}

int main()
{
	int res = 0;
	int p[10] = { 1,2,3,4,5,6,7,8,9,10 };
	res = max_element(p, 10);
	cout << res;
	return 0;
}
