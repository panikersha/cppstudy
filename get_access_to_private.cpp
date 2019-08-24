

#include "pch.h"
#include <iostream>
#include <cstddef> 
#include <cstring> 

using namespace std;

struct Cls {
	Cls(char c, double d, int i):c(c),d(d),i(i){};
private:
	char c;
	double d;
	int i;
};

struct Cls2 {
public:
	Cls2(char c, double d, int i) :c(c), d(d), i(i) {};
public:
	char c;
	double d;
	int i;
};


char &get_c(Cls &cls) {

	Cls * temp = &cls;
	Cls2 t('b', 4.3, 7);

	Cls2 * t_p = &t;
	char * cls2_c = &t.c;
	int size = cls2_c - (char*)t_p;


	return *((char*)temp + size);
}


double &get_d(Cls &cls) {

	Cls * temp = &cls;
	Cls2 t('b', 4.3, 7);

	Cls2 * t_p = &t;
	double * cls2_d = &t.d;
	int size = cls2_d - (double*)t_p;


	return *((double*)temp + size);
}

int &get_i(Cls &cls) {
	
	Cls * temp = &cls;
	Cls2 t('b', 4.3, 7);

	Cls2 * t_p = &t;
	int * cls2_i = &t.i;
	int size = cls2_i - (int*)t_p;


	return *((int*)temp + size);
}


int main()
{

	Cls cl('a',4.1,3);
	char c = get_c(cl);
	cout << c << endl;
	double d = get_d(cl);
	cout << d << endl;
	int i = get_i(cl);
	cout << i << endl;
	return 0;
}

