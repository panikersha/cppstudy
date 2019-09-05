#include <iostream>
using namespace std;

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * binary) = 0;
    virtual ~Visitor() { }
    
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * visitor) const  = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}
    void visit(Visitor * visitor) const { visitor->visitNumber(this); }
    double evaluate() const {return value;}
    double get_value() const { return value; }
     ~Number(){}
private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }
    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }
    Expression const * get_left()  const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }
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


struct PrintBinaryOperationsVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout<<number->get_value();
     }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        if (bop->get_op() == '+' or bop->get_op() == '-')
            std::cout<<"(";

        bop->get_left()->visit(this);
        std::cout << bop->get_op() << " ";
        bop->get_right()->visit(this);
        if (bop->get_op() == '+' or bop->get_op() == '-')
            std::cout<<")";
    }
};

int main()
{

Expression * sube = new BinaryOperation(new Number(4.5), '+', new Number(5));

Expression * expr = new BinaryOperation(new Number(3), '*', sube);


//std::cout << expr->evaluate() << std::endl;


//Expression const * expr = get_expression();
PrintBinaryOperationsVisitor visitor;
expr->visit(&visitor);


delete expr;
return 0;
}
