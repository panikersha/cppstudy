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

int main()
{
Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
Expression * expr = new BinaryOperation(new Number(3), '+', sube);

std::cout << expr->evaluate() << std::endl;

delete expr;
return 0;
}
