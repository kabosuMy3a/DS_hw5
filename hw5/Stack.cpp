#include <iostream>
#include "Stack.h"

using namespace std; 

#define MAX_SIZE 100
#define STRING_MAX 20

Stack::Stack() {

	top = -1;
	max_size = MAX_SIZE ;
	box = new char*[max_size];
	for(int i=0; i< max_size ; i++){
		box[i] = new char[STRING_MAX];
	}
}

Stack::Stack(int max_num) {

	top = -1 ;
	max_size = max_num ;
	box = new char*[max_size];
	for(int i=0; i< max_size ; i++){
		box[i] = new char[STRING_MAX];
	}
} 


Stack::~Stack(){

	for(int i =0 ; i< max_size ; i++){
	
		delete [] box[i] ;
	}

	delete [] box;
	
}


bool Stack::IsFull() const {

	return (top==max_size -1);
	

}

bool Stack::IsEmpty() const {
	
	return (top == -1) ;

}

void Stack::Push(Element item){

	if(IsFull())
		cout << "The stack is full" << endl;
	else box[++top] = item ;

}

Element Stack::Pop(){

	if(IsEmpty()){

		cout << "The stack is empty" << endl;
		return '\0' ;
	}
	else 
		return box[top--];


}

void Stack::Print(int top){

	for(int i= 0; i<=top ; i++)
		cout <<box[i] << ' ';
	if (top != -1) cout <<endl;


}


int Stack::getTop() const{


	return top ;

}

Element Stack::Retrive(){
	if (top!= -1)
		return box[top] ;
	else return 0x0;
}

int Stack::getMax(){

	return max_size ;
}
