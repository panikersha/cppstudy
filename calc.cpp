#include <iostream>
using namespace std;

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}
    double evaluate() const {return value;}
    
     ~Number(){}
private:
    double value;
};

struct BinaryOperation : Expression
{

    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }
    double evaluate() const {
    switch (op)
     {
          case '+':
          {
               return left->evaluate() + right->evaluate();
               break;
          }
          case '-':
          {
               return left->evaluate() - right->evaluate();
               break;
          }
          case '*':
          {
               return left->evaluate() * right->evaluate();
               break;
          }
          case '/':
          {
               return left->evaluate() / right->evaluate();
               break;
          }

     }
    }
    ~BinaryOperation()
    {
         delete left;
         delete right;
    }
private:
    Expression const * left;
    Expression const * right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right)
{
	int* lvptr = *(int**)left;
	int* rvptr = *(int**)right;

	if (rvptr == lvptr)
		return true;
	else return false;

}

struct ScopedPtr
{

	 explicit ScopedPtr(Expression *ptr = 0)
	 {
		 this->ptr_ = ptr;
	 }
	 ~ScopedPtr()
	 {
		 delete ptr_;
	 }
	 Expression* get() const
	 {
		 return ptr_;
	 }
	 Expression* release()
	 {
		 Expression *p = ptr_;
		 ptr_ = 0;
		 return p;
	 }
	 void reset(Expression *ptr = 0)
	 {
		 delete ptr_;
		 ptr_ = ptr;
	 }
	 Expression& operator*() const
	 {
		 return *ptr_;
	 }
	 Expression* operator->() const
	 {
		 return ptr_;
	 }


private:
	// запрещаем копирование ScopedPtr
	ScopedPtr(const ScopedPtr&);
	ScopedPtr& operator=(const ScopedPtr&);

	Expression *ptr_;
};

int main()
{
Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
Expression * expr = new BinaryOperation(new Number(3), '+', sube);
Number * num = new Number(5.3);
std::cout << expr->evaluate() << std::endl;
bool ch = true;
	ch = check_equals(sube, expr);
	std::cout << ch;
	ch = check_equals(sube, num);
	std::cout << ch;
delete expr;
return 0;
}
