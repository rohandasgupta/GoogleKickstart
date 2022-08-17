#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	//cout << "hi";
	string x = "";
	getline(cin,x);
	//cout << "\n";
	//cout << x;
	string y = "";
	getline(cin, y);
	//cout << "\n";
	//cout << y;
	string z;
	getline(cin, z);
	cout << "\n";
	//ut << z;
	string a = x + y + z;
	cout << a;
}