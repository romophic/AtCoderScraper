/*//////////////////////////////////////*/
/*/  NULLCT$ (｀･ω･´) <<"Be accept!!"  /*/
/*//////////////////////////////////////*/
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <cstdint>
#include <math.h>
#include <queue>
#include <stdio.h>
#include <string>
#include <vector>
#define rep(counter, limit) for (int counter = 0; counter < limit; counter++)
typedef long long ll; using namespace std;
int gcd(int a, int b) { if (a % b == 0) { return(b); } else { return(gcd(b, a % b)); } }
int lcm(int a, int b) { return a * b / gcd(a, b); }
bool primenum(int a) { if (a == 1) { return false; }if (a == 2) { return true; }if (a % 2 == 0) { return false; }for (int i = 3; i < sqrt(a) + 1; i += 2) { if (a != i) { if (a % i == 0) { return false; } } }return true; }
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  unsigned long long n,k;
  cin>>n>>k;
  n=n%k;
  if(k/2 < n){
    cout<<k-n<<endl;
  }else{
    cout<<n<<endl;
  }

return 0;
}

