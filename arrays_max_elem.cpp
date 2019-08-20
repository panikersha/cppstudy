
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

int max_elem_pointers(int * p, int * q)
{
	int max = *p;
	for (; p != q; ++p)
		if (*p > max) max = *p;
	return max;
	
}

int * max_elem_position(int *p, int *q)
{
	int * pmax=p;
	for (; p != q; ++p)
		if (*p > *pmax) pmax = p;
	return pmax;
}

bool max_elem_pointer_to_pointer (int *p, int *q, int ** res)
{
	if (p == q) return false;

	*res = p;
	for (; p != q; ++p)
		if (*p > **res) *res = p;
	return true;
}

unsigned strlen(const char *str)
{
	unsigned num = 0;
	while (*str != '\0')
	{
		num++;
		str++;
	}
	return  num;
}

int main()
{

	int p[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << max_element(p, 10) << endl;
	cout << max_elem_pointers(p, p+10) << endl;
	return 0;
}
