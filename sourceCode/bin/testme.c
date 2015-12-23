#include <string>
#include <iostream>

using namespace std;


int main(){


	string one ="18446744073709551615";
	string two = "1";
	if( one > two ){
		cout << one << endl;
	}
	else{
		cout << two << endl;
	}
	return 0;
}