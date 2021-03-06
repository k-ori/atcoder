#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <limits.h>
#include <cstring>
#include <tuple>
#include <cassert>
#include <numeric>
using namespace std;
// type alias
typedef long long LL;
typedef vector < int > VI;
typedef unordered_map < int, int > MAPII;
typedef unordered_set < int > SETI;
typedef pair< int , int > II;
typedef tuple< int, int, int > III;
// repetition
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n)  for(int i=0;i<=(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORR(x,arr) for(auto& x:arr)
#define SZ(a) int((a).size())
// DP
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define ZERO(dp) memset(dp, 0, sizeof(dp))
// minmax
#define SMAX(a,b) a = max(a,b)
#define SMIN(a,b) a = min(a,b)
// debug cerr
#define TRACE true
#define dump(x) if(TRACE) { cerr << #x << " = " << (x) << endl; }
#define dump2(x,y) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl; }
#define dump3(x,y,z) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl; }
#define dump4(x,y,z,a) if(TRACE) { cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << ", " << #a << " = " << (a) << endl; }
#define dumpAR(ar) if(TRACE) { FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }

/*
 
 4/28/2018
 
 21:20-21:38 AC
 
    S[i..j] = 0, S[0..j] = S[0..i-1] + S[i..j] = A
 => S[0..i-1] = A
 
 Editorials:
  - https://img.atcoder.jp/agc023/editorial.pdf
  - https://youtu.be/8BHBFMrZ8VM?t=441
  - http://ferin-tech.hatenablog.com/entry/2018/04/29/003222
 
 Twitter comments:
  - https://twitter.com/evima0/status/990235202222936064
  - https://twitter.com/iwashi31/status/990247602326130688
  - https://twitter.com/torus711/status/990235031430840320
  - https://twitter.com/kjuner8/status/990234726383239168
  - https://twitter.com/satanic0258/status/990234655826763776
 
 */

// $ g++ -std=c++11 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=2e5+1;
int N;
LL A[MAX_N];
LL solve() {
  unordered_map<LL,LL> M;
  LL res=0,sum=0;
  M[0]=1;
  REP(i,N) {
    sum+=A[i];
    if(M.count(sum)) res+=M[sum];
    M[sum]++;
//    dump2(sum,M[sum]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N;
  REP(i,N) cin>>A[i];
  cout<<solve()<<endl;
  return 0;
}
