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
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>    // bitset
#include <cctype>    // isupper, islower, isdigit, toupper, tolower
#include <cstdint>   // int66_t, int*_t
#include <cstdio>    // printf
#include <deque>     // deque
#include <iomanip>   //setfill(char)
#include <ios>       //left,right
#include <iostream>  // cout, endl, cin
#include <map>       // map
#include <queue>     // queue, priority_queue
#include <set>       // set
#include <stack>     // stack
#include <string>    // string, to_string, stoi
#include <tuple>     // tuple, make_tuple
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <utility>       // pair, make_pair
#include <vector>        // vector
#ifdef BOOST
#include <boost/multiprecision/cpp_int.hpp> // cpp_int
using namespace boost::multiprecision;
#endif
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;
using namespace std;
#ifdef CGCC
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
int setup(void) { // set
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}
int lenght(char *str) { // getcharlengh
  int i = 0;
  while (str[i]) {
    i++;
  }
  return i;
}
int gcd(long long a, long long b) {
  if (a < b)
    return gcd(b, a);
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
    return b + 1;
  } else {
    return b;
  }
}
int kuridown(double a) {
  int b = int(a);
  return b;
}
int run(void);
int main(){
  setup();
  run();
  return 0;
}
int run(void){

  int n,r;
  cin>>n>>r;
  int ans=0;
  if(10 > n){
    ans=r+(100*(10-n));
  }else{
    ans=r;
  }

  cout<<ans<<endl;
  return 0;
}

