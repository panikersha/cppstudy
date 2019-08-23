
#include "pch.h"
#include <iostream>

using namespace std;

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
	int ** res_a = new int *[cols];
	res_a[0] = new int[rows * cols];

	for (unsigned i = 1; i!=cols;++i)
	{
		res_a[i] = res_a[i - 1] + rows;
	}
	for (unsigned i = 0; i < rows; ++i)
		for (unsigned j = 0; j < cols; ++j)
		{
			res_a[j][i] = m[i][j];
		}
			
	return res_a;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
	int min = m[0][0];
	int * min_row = m[0];
	int i_min = 0;
	for(int i = 0; i<rows; ++i)
		for(int j = 0; j<cols; j++)
		{
			if (m[i][j] < min)
			{
				min = m[i][j];
				min_row = m[i];
				i_min = i;
			}
		}
	m[i_min] = m[0];
	m[0] = min_row;

}

int main()
{

	/*char * row;
	row = getline(); 
	cout << row << endl;
	delete [] row;
	row = 0;*/


	int ** a = new int *[2];
	a[0] = new int[2 * 3]{1,2,3,1,2,3};
	for (unsigned i = 1; i != 2; ++i)
	{
		a[i] = a[i - 1] + 3;
	}

	int ** new_a = transpose(a, 2, 3);

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			cout << new_a[i][j];

	return 0;
}

