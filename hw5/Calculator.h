#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
class Calculator{
  private:
    Stack1 stack1; // operator
    Stack2 stack2; // operand
    string inflix_exp, postfix_exp;
  public:
    // Implement the following as member functions
    Calculator();
    Read(string exp);
    tokenizer();
    Convert_infix2postfix();
    float Evaluate();
}


#endif
