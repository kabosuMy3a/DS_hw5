#include "Calculator.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stack>
#include <cstdlib>

#define MAX_SIZE 100
#define STRING_MAX 20

using namespace std;



Calculator::Calculator(){

	stackOperator = new Stack();
	//stackOperand = new Stack();
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
	//delete stackOperand;
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


	if (opt.compare("stack1") == 0) stackOperator->Print(stackOperator->getTop());
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

void Calculator::Tokenizer(string opt){
	
/*	for(int i=0 ; i<MAX_SIZE ; i++) {
		strcpy(tokendString[i],infix_exp.c_str());
	}		

	cout << tokendString[0] << endl;
	
*/	
	char src[100] ;
	if (opt.compare("infix")==0) 
		strcpy(src,infix_exp.c_str());
	else if (opt.compare("postfix")==0) 
		strcpy(src,postfix_exp.c_str());
	else strcpy(src,postfix_exp.c_str());
	

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
	
		else if (src[src_index] == ',') src_index ++;

		else{

			 token_temp[token_index] = src[src_index];
			 token_temp[token_index+1] =  0x0 ; //always index 1;
			 //cout<<token_temp <<endl;
			 strcpy(tokendString[tokendStringCount++],token_temp);
			 src_index ++;
	
		}

	}
	
	tokendString[tokendStringCount] = 0x0;
	tokenNum = tokendStringCount ;	
	

}

void Calculator::Convert_infix2postfix(){

	int i = 0;

	while(tokendString[i]!= 0x0 ){
		
		string tempForCtoS = tokendString[i];
		string temp;
		int this_priority = 0;
		int priorityOfTop = checkPriority() ;
	

		if (tempForCtoS.compare("(")==0){
		
			this_priority = 3;
			stackOperator->Push(tokendString[i]); 		
		}

		else if(tempForCtoS.compare(")")==0){
			
			while(priorityOfTop !=3 ){
				temp = stackOperator->Pop();
				if (stackOperator->getTop() == -1){
					 cout << "you input wrong parenthetics set" << endl;
					 break;
				}
				postfix_exp.append(temp);
				priorityOfTop = checkPriority();
			
			}
			temp = stackOperator->Pop();	
			
		}

		else if(tempForCtoS.compare("+")==0){
		
			this_priority = 1;
		
			if (this_priority <= priorityOfTop){ 
				if (this_priority <= priorityOfTop && priorityOfTop != 3){
					temp = stackOperator->Pop();
					postfix_exp.append(temp);		
				}
				stackOperator->Push(tokendString[i]);
			}
			else stackOperator->Push(tokendString[i]); 	
		}

		else if(tempForCtoS.compare("-")==0){
		
			this_priority = 1;
		
			if (this_priority <= priorityOfTop){ 
				if (this_priority <= priorityOfTop && priorityOfTop != 3){
					temp = stackOperator->Pop();
					postfix_exp.append(temp);		
				}
				stackOperator->Push(tokendString[i]);
			}
			else stackOperator->Push(tokendString[i]);	
		}

		else if(tempForCtoS.compare("*")==0){
		
			this_priority = 2;
		
			if (this_priority <= priorityOfTop){ 
				if (this_priority <= priorityOfTop && priorityOfTop != 3){
					temp = stackOperator->Pop();
					postfix_exp.append(temp);		
				}
				stackOperator->Push(tokendString[i]);
			}
			else stackOperator->Push(tokendString[i]);	
		}

		else if(tempForCtoS.compare("/")==0){
		
			this_priority = 2;
		
			if (this_priority <= priorityOfTop){ 
				if (this_priority <= priorityOfTop && priorityOfTop != 3){
					temp = stackOperator->Pop();
					postfix_exp.append(temp);		
				}
				stackOperator->Push(tokendString[i]);
			}
			else stackOperator->Push(tokendString[i]);	
		}

		else{
			 postfix_exp.append(tempForCtoS);
			 postfix_exp.append(",");  
		}

		
		i++;		

	}

	while (stackOperator->getTop() != -1){
		if (checkPriority()==3){
			cout << "you input wrong parenthetics set" << endl;
		} 
		string temp;
		temp = stackOperator->Pop();
		postfix_exp.append(temp);

	}
	

}


int Calculator::checkPriority(){


	int priority = 0;
	int TOP = stackOperator->getTop();
	string tempForCtoS ;
	if (TOP!= -1)
		tempForCtoS =  stackOperator->Retrive() ;
	else return 0;
	//cout << stackOperator->Retrive();
	
	
	if (tempForCtoS.compare("(")==0){
		priority = 3;					
	}

	else if(tempForCtoS.compare(")")==0){

		priority = -1 ;
	}

	else if(tempForCtoS.compare("+")==0){
		priority = 1 ;
	}

	else if(tempForCtoS.compare("-")==0){
		priority = 1;
	}

	else if(tempForCtoS.compare("*")==0){
		priority = 2;
	}

	else if(tempForCtoS.compare("/")==0){
		priority = 2;
	}
	else priority = -1 ;


	return priority ; 

} 


float Calculator::Evaluate(){

	Tokenizer("postfix");
	int i=0;
	stack <float> st ;
	float temp1,temp2; 

	while(tokendString[i]!=0x0){

		string tempForCtoS = tokendString[i] ; 


		if(tempForCtoS.compare("+")==0){
			
			temp2 =	st.top();
			st.pop();
			temp1 = st.top();
			st.pop();
			st.push(temp1+temp2);
			

		}	

		else if(tempForCtoS.compare("-")==0){
		
			temp2 =	st.top();
			st.pop();
			temp1 = st.top();
			st.pop();
			st.push(temp1-temp2);
		

		}
	
		else if(tempForCtoS.compare("*")==0){

			temp2 =	st.top();
			st.pop();
			temp1 = st.top();
			st.pop();
			st.push(temp1*temp2);
		

		}

		else if(tempForCtoS.compare("/")==0){

			temp2 =	st.top();
			st.pop();
			temp1 = st.top();
			st.pop();
			st.push(temp1/temp2);
			

		}

		else{
		
			st.push(atof(tokendString[i])) ;

		}
	
		i++;

	}	
	
	return st.top() ;
}
