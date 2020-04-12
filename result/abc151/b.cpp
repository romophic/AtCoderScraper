////////////////////////////////////////////////////////////////
//
//    (☝ ՞ਊ ՞)☝ << Be accept!!
//
//    C++ format for competitive professional v1.0
//
//    GCC is recommendation.
//
////////////////////////////////////////////////////////////////

#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<time.h>
#include<random>
#include<thread>
#include<boost/multiprecision/cpp_int.hpp>

#define rep(i,n) for(int i = 0;i < n;i++)
#define Be return
#define accept 0;

using ll = long long;
using namespace std;
using namespace boost::multiprecision;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

int inline setup(void) {//set
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}
int lenght(char* str){//getcharlengh
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}
int gcd(long long a, long long b) {
	if (a < b)return gcd(b, a);
	long long r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}
void func(int *a) {
	
	cout << a[0] << endl;

}
int main(int argc, const char* argv[]) {
	setup();

	int n, k, m,a;
	cin >> n >> k >> m;
	int num;
	a = 0;
	rep(i, n - 1) {
		cin >> num;
		a += num;
	}
	if (n * m > a + k) {
		cout << "-1" << endl;
	}
	else {
		if (n * m - a < 0) {
			cout << "0" << endl;
		}
		else {
			cout << n * m - a << endl;
		}
	}


	Be accept
}

