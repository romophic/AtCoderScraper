/*------------------------------------------------,
|  __                                       __    |
| |  |--.-----.---.-.----.----.-----.-----.|  |_  |
| |  _  |  -__|  _  |  __|  __|  -__|  _  ||   _| |
| |_____|_____|___._|____|____|_____|   __||____| |
|                                   |__|          |
`------------------------------------------------*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

typedef long long ll;
using namespace std;
#define INF 2147483647
#define MOD 10000007
#define REP(count_ver, lower, upper) for (long long count_ver = lower; count_ver < upper; count_ver++)

int gcd(int a, int b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}
int lcm(int a, int b) { return a * b / gcd(a, b); }
vector<long long> divisor(long long n) {
  vector<long long> ret;
  for(long long i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  return (ret);
}

void execute(){

  int n,k;
  cin>>n>>k;
  int ans=1;
  REP(i,0,n){
    if(ans*2 > ans+k){
      ans+=k;
    }else if(ans*2 < ans+k){
      ans*=2;
    }else{
      ans+=k;
    }
  }
  cout<<ans<<endl;

}
int main() {

  cin.tie(0);
  ios::sync_with_stdio(0);
  //cout<<fixed<<setprecision(20);

  execute();

  return 0;
}

