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
#include<stdio.h>
#include<time.h>
#include<random>
#include<map>
#include<thread>
#include<tuple>
#include<boost/multiprecision/cpp_int.hpp>
#define rep(i,n) for(int i = 0;i < n;i++)
using ll = long long;
using namespace std;
using namespace boost::multiprecision;//cpp_int
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
#define DEBUG
int main(int argc, const char* argv[]) {
	setup();
		
	int n, m;
	cin >> n >> m;
	if (n == m) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

