////////////////////////////////////////////////////////////////
//
//    (☝ ՞ਊ ՞)☝ << Be accept!!
//
//    C++ format for competitive professional v1.0
//
//    need gcc & boost::c++
//
////////////////////////////////////////////////////////////////
//#define BOOST
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
#include<boost/multiprecision/cpp_int.hpp>// cpp_int
using namespace boost::multiprecision;
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
int iinput(void) {
    int a = 0;
    cin >> a;
    return a;
}
int dinput(void) {
    double a = 0;
    cin >> a;
    return a;
}
string sinput(void) {
    string a = "";
    cin >> a;
    return a;
}
int kuriup(double a) {
    int b = int(a);
    if (a != b) {
        return b+1;
    }
    else {
        return b;
    }
}
int kuridown(double a) {
    int b = int(a);
    return b;
}
#define DEBUG
int main(int argc, const char* argv[]) {
    setup();

    int n;
    cin>>n;
    vector<int> list(n);
    rep(i,n)cin>>list[i];

    sort(list.begin(),list.end());
    rep(i,n){
      if(list[i] == list[i+1]){
          cout<<"NO"<<endl;
          return 0;
        }
    }

    cout<<"YES"<<endl;

    return 0;
}

