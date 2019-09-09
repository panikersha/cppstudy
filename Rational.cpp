#include <iostream>
using namespace std;

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void print() const
    {
        cout<<this->numerator_<<'\\'<<this->denominator_<<endl;
    }

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }
    Rational & operator +=(Rational const& r2)
    {
        this->add(r2);
        return *this;
    }
      Rational & operator /=(Rational const& r2)
    {
        this->div(r2);
        return *this;
    }

 Rational & operator *=(Rational const& r2)
    {
        this->mul(r2);
        return *this;
    }
     Rational & operator -=(Rational const& r2)
    {
        this->sub(r2);
        return *this;
    }
      Rational operator+() const
    {
       
        return *this;
    }
    
    Rational operator-() const
    {
        Rational n(this->numerator_, this->denominator_);
        n.neg();
        return n;
    }
     
private:
    int numerator_;
    int denominator_;
};


 Rational operator+(Rational  a, Rational const& b)
{
	return a += b;
};
Rational operator*(Rational  a, Rational const& b)
{
	return a *= b;
};
Rational operator/(Rational  a, Rational const& b)
{
	return a /= b;
};
Rational operator-(Rational  a, Rational const& b)
{
	return a -= b;
};

bool operator==(Rational const& a, Rational const& b)
{
	return   a.get_numerator() == b.get_numerator() && a.get_denominator() == b.get_denominator();
}

bool operator!=(Rational const& a, Rational const& b)
{
	return  !(a == b);
}

bool operator<(Rational const& a, Rational const& b)
{
	return (int)a.get_numerator() * (int)b.get_denominator() < (int)b.get_numerator() * (int)a.get_denominator();
}

bool operator>(Rational const& a, Rational const& b)
{
	return  b < a;
}

bool operator>=(Rational const& a, Rational const& b)
{
	return  !(a < b);
}

bool operator<=(Rational const& a, Rational const& b)
{
	return  !(b < a);
}

int main()
{
const Rational a(2,3);
Rational b (1,3);
a.print();
Rational c = -a;
a.print();

Rational d = +a;

 if ((-a).to_double() != -1.0 / 4.0)
 cout<<"Hello";
 else
 cout<< "buy";
a.print();
return 0;
}
