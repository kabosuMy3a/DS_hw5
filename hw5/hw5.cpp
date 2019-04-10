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
	getline(cin,opt);; 	

	myCal->Tokenizer();
	
	myCal->Print(opt);


}
