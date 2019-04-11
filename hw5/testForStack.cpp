#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {



	stack<float> st;
	st.push(1.3);
	st.push(2.3);
	cout << st.top()<<endl;
	float temp1,temp2 ;
	
	temp2=st.top();
	st.pop();
	temp1=st.top();
	st.pop();
	
	cout << temp1/temp2 <<endl;




}
