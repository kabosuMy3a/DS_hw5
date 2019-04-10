#include "Calculator.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#define MAX_SIZE 100
#define STRING_MAX 20
using namespace std;

Calculator::Calculator(){

	Stack * stackOperator = new Stack();
	Stack * stackOperand = new Stack();
	infix_exp = "" ;
	postfix_exp = ""; 
	
	tokendString = new char * [MAX_SIZE];
	for(int i=0; i<MAX_SIZE ; i++){
		tokendString[i] = new char[STRING_MAX];
	}	
	tokenNum = 0;

}

Calculator::~Calculator(){

	delete stackOperator;
	delete stackOperand;
	for(int i =0 ; i <MAX_SIZE ; i++){
		delete [] tokendString[i];
	}
	delete [] tokendString;

}



void Calculator::Read(string exp){

	ifstream infile(exp.c_str());
	
	string s ;
	
	while (getline(infile,s))
		infix_exp = s ;


}

void Calculator::Print(string opt){


	if (opt.compare("stack") == 0) cout << "kueeeek"<< endl;
	else if (opt.compare("infix")==0) cout << infix_exp << endl;
	else if (opt.compare("postfix")==0) cout <<postfix_exp<<endl;
	else if (opt.compare("token")==0){
		cout << tokenNum <<endl;
		for(int i=0 ; i< tokenNum ; i++){
			cout << tokendString[i] <<endl;
		}
	}
	else cout << " Wrong" << endl;


}

void Calculator::Tokenizer(){
	
/*	for(int i=0 ; i<MAX_SIZE ; i++) {
		strcpy(tokendString[i],infix_exp.c_str());
	}		

	cout << tokendString[0] << endl;
	
*/
	char src[100] ;
	strcpy(src,infix_exp.c_str());
	
	int src_index = 0;
	//int srclen = strlen(src);
	int tokendStringCount = 0;

	while(src[src_index]!=0x0){

		char token_temp[20];
		int token_index =0 ;
 		
		if(isdigit(src[src_index])!=0){
			int j= 1; 
			while( isdigit(src[src_index+j]) !=0 || src[src_index+j] == '.' || src[src_index+j] == ' ') j++;
			//cout << j <<"  |  ";
			for(token_index ; token_index < j ; token_index++){
				token_temp[token_index] = src[src_index+token_index];
			}
			//cout <<token_index < " &  " ;
			token_temp[token_index]= 0x0;
			//cout << token_temp <<endl;
			strcpy(tokendString[tokendStringCount++],token_temp);
			src_index = src_index + token_index; 

		}		 		
		
		else if (src[src_index] == '\n' || src[src_index] == '\t' || src[src_index] == ' ') src_index ++;
		

		else{

			 token_temp[token_index] = src[src_index];
			 token_temp[token_index+1] =  0x0 ; //always index 1;
			 //cout<<token_temp <<endl;
			 strcpy(tokendString[tokendStringCount++],token_temp);
			 src_index ++;
	
		}

	}
	

	tokenNum = tokendStringCount ;	
	

}
