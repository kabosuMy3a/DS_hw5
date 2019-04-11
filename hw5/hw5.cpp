#include <iostream>
#include "Stack.h"
#include "Calculator.h"

using namespace std;

int main(){

	Calculator * myCal = new Calculator() ;

	string filename,opt;
	getline(cin,filename);
	//cin.ignore(1000,'\n');
	myCal->Read(filename);
	//getline(cin,opt);; 	
	
	//string token_opt;
	//getline(cin,token_opt);
	myCal->Tokenizer("infix");
//	myCal->Print(opt);
	myCal->Convert_infix2postfix();
//	myCal->Print("postfix");
	float result = myCal->Evaluate();
	
	if (result == int(result)) cout << result <<endl;
	else {
		cout<<fixed;
		cout.precision(1);
		cout<<result<<endl;
	}
}	
