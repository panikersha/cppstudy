#include <iostream>
#include <cstddef>

using namespace std;

template <typename T>
class Array
{
    // Список операций:
    //
public:
     explicit Array(size_t size = 0, const T& value = T()):size_(size), data_(new T[size])
     {
          for (size_t i = 0; i < size; ++i) {
            data_[i] = value;
        }
     }
 
     Array(const Array &a):size_(a.size_), data_(new T[size_])
     {
         for (size_t i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
     }
 
     ~Array()
     {
         delete [] data_;
     }
     	void prnt()
	{
		for (size_t i = 0; i < size_; ++i)
			cout << *(data_+i);
		cout << endl;
	}
   
     Array & operator=(Array & a)
	{
		if(this!=&a)
		{
            delete [] data_;
            size_ = a.size_;
            data_ = new T[size_];
            for (size_t i = 0; i != size_; ++i)
			data_[i] = a.data_[i];
		
			return *this;
		}
	}
 
     size_t size() const
     {
         return size_;
     }
  
     T& operator[](size_t i)
     {
         return data_[i];
     }
     const T& operator[](size_t i) const
     {
        return data_[i];
     }
 
private:
	size_t size_;
	T * data_;
};



/******************************T E S T S*********************/
void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main(int c, char** v)
{

	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	return 0;
}

void test0()
{
	{
		cout << endl << "*****Test 0**********" << endl;
		cout << endl << "*****CHAR**********" << endl;
		Array<char> ar(size_t(5), '0');
		Array<char> x(size_t(4), '4');
		ar = x;
		ar.prnt();

		Array<char> x2(size_t(6), '6');
		ar = x2;
		ar.prnt();
	}
	{
		cout << endl << "*****STRING**********" << endl;
		Array<string> cr(size_t(5), "0");
		Array<string> cx(size_t(4), "4");
		cr = cx;
		cr.prnt();

		Array<string> cx2(size_t(6), "6");
		cr = cx2;
		cr.prnt();
	}
	{
		cout << endl << "*****INT**********" << endl;
		Array<int> ir(size_t(5), 0);
		Array<int> ix(size_t(4), 4);
		ir = ix;
		ir.prnt();

		Array<int> ix2(size_t(6), 6);
		ir = ix2;
		ir.prnt();
	}

	{
		cout << endl << "*****DOUBLE**********" << endl;
		Array<double> dr(size_t(5), 0.0);
		Array<double> dx(size_t(4), 4.0);
		dr = dx;
		dx.prnt();

		Array<double> ix2(size_t(6), 6.0);
		dr = ix2;
		dr.prnt();
	}
	return;
}


void test1()
{
	{
		cout << endl << "*****Test 1(assigment)**********" << endl;
		Array<char> ar(size_t(100), '0');
		Array<char> x(size_t(0), '1');
		ar = x;
		ar.prnt();
	}
	{
		cout <<  "*****STRING**********" << endl;
		Array<string> cr(size_t(100), "0");
		Array<string> cx(size_t(0), "1");
		cr = cx;
		cr.prnt();

		Array<string> cx2(size_t(2), "55");
		cr = cx2;
		cr.prnt();
	}
	{
		cout << "*****INT**********" << endl;
		Array<int> cr(size_t(100), 0);
		Array<int> cx(size_t(0), 15);
		cr = cx;
		cr.prnt();

		Array<int> cx2(size_t(2), 55);
		cr = cx2;
		cr.prnt();
	}
	return;
}
void test2()
{
	cout << endl << "*****Test 2(copy constructor)**********" << endl;
	{
		cout << "*****CHAR**********" << endl;
		Array<char> x(size_t(3), '3');
		Array<char> ar(x);
		ar.prnt();
	}
	{
		cout << "*****STRING**********" << endl;
		Array<string> x(size_t(3), "333");
		Array<string> ar(x);
		ar.prnt();
	}

	return;
}

void test3()
{
	cout << endl << "*****Test 3(Empty)**********" << endl;
	{
		cout << "*****CHAR**********" << endl;
		Array<char> ar(size_t(0), '0');
		ar = ar;
		ar.prnt();
	}
	{
		cout << "*****STRING**********" << endl;
		Array<string> ar(size_t(0), "0");
		ar = ar;
		ar.prnt();
	}
	return;
}

void test4()
{
	cout << endl << "*****Test 4(assigment A=A) **********" << endl;
	{
		Array<char> ar(size_t(4), '0');
		ar = ar;
		ar.prnt();
	}
	return;
}
void test5()
{
	cout << endl << "*****Test 5(out bound)**********" << endl;
	{
		cout << "*****more**********" << endl;
		Array<char> ar(size_t(4), '0');
		cout << ar[10] << endl;
	}
	{
		cout << "*****less**********" << endl;
		Array<char> ar(size_t(4), '0');
		cout << ar[-10] << endl;
	}
	return;
}

void test6()
{
	cout << endl << "*****Test 6(pointer)**********" << endl;
	{
		Array<char> *ar = new Array<char>(size_t(4), '4');
		ar->prnt();
		delete ar;
	}
	{
		Array<char> *ar = new Array<char>(size_t(5), '5');
		ar->prnt();
		Array<char> *xr = ar;
		xr->prnt();
		delete ar;
	}
	return;
}
