#include<iostream>
#include<string>
using namespace std;
int main() {
	
	int n;
	string s;
	cin >> n >> s;
	if (s.substr(0, n / 2) == s.substr(n / 2, n)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}
