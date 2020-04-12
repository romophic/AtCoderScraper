//////////////////////////
/*      _        ____   */
/*  U  /"\  u U /"___|  */
/*   \/ _ \/  \| | u    */
/*   / ___ \   | |/__   */
/*  /_/   \_\   \____|  */
/*   \\    >>  _// \\   */
/*  (__)  (__)(__)(__)  */
/*  Compro by NULL_CT©  */
//////////////////////////
/*STL Libs*/
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <chrono>
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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

/*Boost to boost compile time*/
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#define int long long // Black Magic
#define REP(I, LIM) for (int I = 0; I < LIM; I++)
#define ALL(LIST) (LIST.begin()), (LIST.end())

using namespace std;
using bint = boost::multiprecision::cpp_int;

constexpr int MOD = 10000007;

vector<int> divisor(int n) {
  vector<int> head, tail;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      head.push_back(i);
      if (i * i != n)
        tail.push_back(n / i);
    }
  }
  head.insert(head.end(), tail.rbegin(), tail.rend());
  return (head);
}

//--------------------------------

void execute() {
  int n;
  cin>>n;
  vector<pair<int,int> > ll(n);
  REP(i,n){ cin>>ll[i].first>>ll[i].second; }
  int count=0;

  long double ans=0;
  sort(ALL(ll));
  do{
    count++;
    long double sum=0;

    for(int i=0;i<ll.size()-1;i++){
      sum+=sqrt(pow(ll[i].first-ll[i+1].first,2)+
                pow(ll[i].second-ll[i+1].second,2));
    }
    ans+=sum;
    cerr<<count<<":"<<sum<<endl;
  } while(next_permutation(ALL(ll)));
  cout<<ans/count<<endl;
}

//--------------------------------

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout<<fixed<<setprecision(20);

  execute();

  return (0);
}

