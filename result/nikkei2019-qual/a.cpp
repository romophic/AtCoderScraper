#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main() {

	int n, a, b;
	cin >> n >> a >> b;

	if (a < b) {
		cout << a << endl;
	}
	else {
		cout << b << endl;
	}
	
	if (abs(n - (a + b)) != n - (a + b)) {
		cout << (a + b) - n << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}
