#ifndef ADIOS2_EXPRESSION_H_
#define ADIOS2_EXPRESSION_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

/********* Variable Lookup Table ******************/

std::map<std::string, std::string> var_lookup_table;

bool add_var(char *alias, char *var_path)
{
  std::cout << "Adding alias to lookup table: '" << alias << "' is found at '" << var_path << "'" << std::endl;
  var_lookup_table[alias] = var_path;
  return true;
}

const char* get_var_path(char *alias)
{
  std::string temp = alias;
  return var_lookup_table[temp].c_str();
}

/*************************************************/

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

  virtual void get_var (std::vector<std::string> *vec)
  {
  }
};

template <class T>
class Alias: public Expression<T>
{
 private:
  std::string alias;
  std::string path;
  
 public:
  Alias(char *a)
  :alias(a)
  {
    std::cout << "Constructing Alias expression" << std::endl;
    path = var_lookup_table[alias];
  }
  
  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }
  
  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "(Alias: expression variable \'" + alias + "\' maps to adios Variable \'" + path + "\')\n";
  }

  std::string print()
  {
    return "(Alias: " + alias + ":" + path + ")";
  }

  void get_var (std::vector<std::string> *vec)
  {
    vec->push_back(path);
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
class Sqrt: public Expression<T>
{
 private:
  Expression<T> *Operand;
  
 public:
  Sqrt(Expression<T> *o)
    :Operand(o)
  {
    std::cout << "Constructing Sqrt expression" << std::endl;
  }
  
  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }

  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "Sqrt: " + Operand->printpretty(indent + "    ") + "\n";
  }

  std::string print()
  {
    return "(Sqrt: " + Operand->print() + ")";
  }

  virtual void get_var (std::vector<std::string> *vec)
  {
    Operand->get_var(vec);
  }
};

template <class T>
class Pow: public Expression<T>
{
 private:
  Expression<T> *Operand;
  Expression<T> *Exponent;
  
 public:
  Pow(Expression<T> *o, Expression<T> *e)
    :Operand(o), Exponent(e)
  {
    std::cout << "Constructing Pow expression" << std::endl;
  }
  
  bool evaluate (Variable<T> *result)
  {
    // Implementation
    std::cout << print();
    return false;
  }

  std::string printpretty(std::string indent)
  {
    return "\n" + indent + "Pow: " + Operand->printpretty(indent + "    ") + "\n" + indent + "            " + Exponent->printpretty(indent + "    ");
  }

  std::string print()
  {
    return "(Pow: " + Operand->print() + " to the power of " + Exponent->print() + ")";
  }

  virtual void get_var (std::vector<std::string> *vec)
  {
    Operand->get_var(vec);
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

  virtual void get_var (std::vector<std::string> *vec)
  {
    Operand1->get_var(vec);
    Operand2->get_var(vec);
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

  virtual void get_var (std::vector<std::string> *vec)
  {
    Operand1->get_var(vec);
    Operand2->get_var(vec);
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

  virtual void get_var (std::vector<std::string> *vec)
  {
    Operand1->get_var(vec);
    Operand2->get_var(vec);
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

  virtual void get_var (std::vector<std::string> *vec)
  {
    Operand1->get_var(vec);
    Operand2->get_var(vec);
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

  virtual void get_var (std::vector<std::string> *vec)
  {
    Operand->get_var(vec);
  }
};

#endif /* ADIOS2_EXPRESSION_H_ */
