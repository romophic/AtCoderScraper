#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp = boost::multiprecision;
using namespace std;
int main()
{

	int a, b;
	cin >> a >> b;
	if (1 <= a && 9 >= a && 1 <= b && 9 >= b)
	{
		cout << a * b << endl;
		return 0;
	}
	cout << -1 << endl;

	return 0;
}
