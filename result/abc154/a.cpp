////////////////////////////////////////////////////////////////
//
//    (☝ ՞ਊ ՞)☝ << Be accept!!
//
//    C++ format for competitive professional v1.0
//
//    need gcc & boost::c++
//
////////////////////////////////////////////////////////////////
#define BOOST
#define CGCC
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#ifdef BOOST
#include<boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;//cpp_int
#endif
#define rep(i,n) for(int i = 0;i < n;i++)
using ll = long long;
using namespace std;
#ifdef CGCC
#pragma once
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
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
		
	string s, t, u;
	int a, b;
	cin >> s >> t >> a >> b >> u;
	if (s == u) {
		cout << a - 1 << endl << b << endl;
	}
	else {
		cout << a << endl << b - 1 << endl;
	}

	return 0;
}

