///////////////////////////////////////////
//root@NULLCT$(☝ ՞ਊ ՞)☝  << "Be accept!!"//
///////////////////////////////////////////
//#define BOOST
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
int setup(void) { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0; }
int lenght(char* str) { int i = 0; while (str[i])i++; return i; }
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
int iinput(void) { int a = 0; cin >> a; return a; }
int dinput(void) { double a = 0; cin >> a; return a; }
string sinput(void) { string a = ""; cin >> a; return a; }
int kuriup(double a) { int b = int(a); if (a != b) { return b + 1; } else { return b; } }
int kuridown(double a) { int b = int(a); return b; }
int run(void);
int main() { setup(); run(); return 0; }
/////////////////////////////////////////////////////////////////////////////////////////
int run(void) {

  int a,b,m;
  cin>>a>>b>>m;
  vector<int> arei(a);
  vector<int> bden(b);
  int nowaribikirei=200000;
  int nowaribikiden=200000;
  for(int i=0;i < a;i++){
    cin>>arei[i];
    nowaribikirei=min(nowaribikirei,arei[i]);
  }
  for(int i=0;i < b;i++){
    cin>>bden[i];
    nowaribikiden=min(nowaribikiden,bden[i]);
  }
  int ans=nowaribikirei+nowaribikiden;
  int xyc[100000][3];
  for(int i=0;i < m;i++){
    cin>>xyc[i][0]>>xyc[i][1]>>xyc[i][2];
    ans=min(ans,(arei[xyc[i][0]-1]+bden[xyc[i][1]-1])-xyc[i][2]);
  }
  cout<<ans<<endl;



  return 0;
}

