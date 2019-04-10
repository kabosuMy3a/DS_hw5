#include <string>
#include "Stack.h"
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

using namespace std;

class Calculator{
  private:
    Stack * stackOperator; // operator
    Stack * stackOperand; // operand
    string infix_exp, postfix_exp;
    char ** tokendString ; 
    int tokenNum ;
	
  public:
    // Implement the following as member functions
    Calculator();
    ~Calculator();
    void  Read(string exp);
    void Tokenizer();
  //  string Convert_infix2postfix();
  //  float Evaluate();
    void Print(string opt);

};


#endif
