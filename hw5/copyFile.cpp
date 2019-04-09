#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv){

    if (argc < 1) return -1;
 
	//string fileName = argv[1]
	
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);

	string s;

	while (getline(infile,s)) 
		outfile << s << endl ;

	return 0;


}
