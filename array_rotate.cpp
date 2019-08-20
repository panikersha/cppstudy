#include "pch.h"
#include <iostream>

using namespace std;

void rotate(int a[], unsigned size, int shift)
{
	int temp = 0;
	for (int i=0;i<shift;i++)
		for(int j=0;j<size-1;j++)
		{
			temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
}


int main()
{
	int res = 0;
	int p[5] = { 1,2,3,4,5 };
	rotate(p, 5,6);
	for (int i = 0; i < 5; i++)
	 cout << p[i];
	return 0;
}
