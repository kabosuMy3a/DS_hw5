#include <iostream>
#include "Stack.h"
//#include "Calculator.h"

using namespace std;

int main(int argc, char * argv[]){

	Stack * myStack = new Stack();

	myStack->Print(myStack->getTop());
	myStack->Push(argv[1]);
	myStack->Push(argv[2]);	
	myStack->Print(myStack->getTop());
	myStack->Push(argv[3]);
	myStack->Print(myStack->getTop());
	cout << "Pop: " << myStack->Pop() << endl;
		


}
