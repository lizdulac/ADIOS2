#include <iostream>
#include <string>
#include <vector>

template <class T>
class Variable
{
 private:
  std::vector<T> data;
  std::string name;
 public:
  std::string getName() { return name;}
};

template <class T>
class Expression
{
public:
  virtual bool evaluate (Variable<T> *result) {return false;};

  virtual std::string printpretty(std::string indent)
  {
    return "\n" + indent + "null";
  }
  
  virtual std::string print()
  {
    return "null";
  }
};

template <class T>
class Number: public Expression<T>
{
private:
  T number;
  
public:
  Number(T num)
    :number(num)
  {
    //std::cout << "Constructing Number expression with number: " << std::to_string(num) << std::endl;
  }

  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }

  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "(Number: " + std::to_string(number) + ")";
  }
  
  std::string print()
  {
    return "(Number: " + std::to_string(number) + ")";
  }
};


template <class T>
class Addition: public Expression<T>
{
 private:
  Expression<T> *Operand1;
  Expression<T> *Operand2;
  
 public:
  Addition(Expression<T> *o1, Expression<T> *o2)
    :Operand1(o1), Operand2(o2)
  {
    std::cout << "Constructing Addition expression" << std::endl;
  }
  
  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }

  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "Addition: " + Operand1->printpretty(indent + "    ") + "\n" + indent + "            " + Operand2->printpretty(indent + "    ");
  }

  std::string print()
  {
    return "(Addition: " + Operand1->print() + " and " + Operand2->print() + ")";
  }
};

template <class T>
class Subtraction: public Expression<T>
{
 private:
  Expression<T> *Operand1;
  Expression<T> *Operand2;
  
 public:
  Subtraction(Expression<T> *o1, Expression<T> *o2)
    :Operand1(o1), Operand2(o2)
  {
    std::cout << "Constructing Subtraction expression" << std::endl;
  }
  
  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }

  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "Subtraction: " + Operand1->printpretty(indent + "    ") + "\n" + indent + "               " + Operand2->printpretty(indent + "    ");
  }

  std::string print()
  {
    return "(Subtraction: " + Operand1->print() + " and " + Operand2->print() + ")";
  }
};

template <class T>
class Multiplication: public Expression<T>
{
 private:
  Expression<T> *Operand1;
  Expression<T> *Operand2;
  
 public:
  Multiplication(Expression<T> *o1, Expression<T> *o2)
    :Operand1(o1), Operand2(o2)
  {
    std::cout << "Constructing Multiplication expression" << std::endl;
  }
  
  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }

  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "Multiplication: " + Operand1->printpretty(indent + "    ") + "\n" + indent + "                  " + Operand2->printpretty(indent + "    ");
  }

  std::string print()
  {
    return "(Multiplication: " + Operand1->print() + " and " + Operand2->print() + ")";
  }
};

template <class T>
class Division: public Expression<T>
{
 private:
  Expression<T> *Operand1;
  Expression<T> *Operand2;
  
 public:
  Division(Expression<T> *o1, Expression<T> *o2)
    :Operand1(o1), Operand2(o2)
  {
    std::cout << "Constructing Division expression" << std::endl;
  }
  
  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }

  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "Division: " + Operand1->printpretty(indent + "    ") + "\n" + indent + "            " + Operand2->printpretty(indent + "    ");
  }

  std::string print()
  {
    return "(Division: " + Operand1->print() + " and " + Operand2->print() + ")";
  }
};

template <class T>
class Negation: public Expression<T>
{
 private:
  Expression<T> *Operand;
  
 public:
  Negation(Expression<T> *o)
    :Operand(o)
  {
    std::cout << "Constructing Negation expression" << std::endl;
  }
  
  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }
  
  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "Negation: " + Operand->printpretty(indent + "    ");
  }

  std::string print()
  {
    return "(Negation: " + Operand->print() + ")";
  }
};
