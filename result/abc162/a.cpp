//////////////////////////////////////////////////////////
//______________________________________________________//
//    ____           __                                 //
//    /   )          / |                                //
//---/__ /-----__---/__|----__----__----__------__--_/_-//
//  /    )   /___) /   |  /   ' /   ' /___)   /   ) /   //
//_/____/___(___ _/____|_(___ _(___ _(___ ___/___/_(_ __//
//                                          /           //
//                                         /            //
//////////////////////////////////////////////////////////
#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <iterator>
#include <cctype>
#include <cstdio>
#include <cstring>
#define rep(counter, limit) for (int counter = 0; counter < limit; counter++)
typedef long long ll; using namespace std;const int INF=1001001001;
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool primenum(int a) { if (a == 1) { return false; }if (a == 2) { return true; }if (a % 2 == 0) { return false; }for (int i = 3; i < sqrt(a) + 1; i += 2) { if (a != i) { if (a % i == 0) { return false; } } }return true; }
int main() {

  string s;
  cin>>s;
  if(s[0]=='7' || (s[1]=='7' || s[2]=='7')){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }

return 0;
}

