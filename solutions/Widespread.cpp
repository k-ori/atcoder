#include <iostream>
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

 7/30/2018

 25:40-25:50 AC

 Editorials:
  - https://atcoder.jp/img/arc075/editorial.pdf
  - https://youtu.be/XTW-Q5buWOk?t=1056
  - http://phwinx.hatenablog.com/entry/2017/06/09/041809
  - http://hamayanhamayan.hatenablog.jp/entry/2017/06/03/231648
  - https://kimiyuki.net/writeup/algo/atcoder/arc-075-d/
  - http://htkb-procon.hateblo.jp/entry/2017/06/04/003542
  - https://ei1333.hateblo.jp/entry/2017/06/04/180652

 x*B is applied to all the monsters.
 (A-B) can be applied to arbitrary monsters at most `x` times.
 Then decision problem can be solved in O(N).

 Larger `x` beats more monsters. Let's go through binary search.

 Summary:
  - decision problem and additional (A-B) damage came up with me quickly

 7/2/2020

 22:24-22:30 solve again

 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
LL H[MAX_N];
int N;
LL A,B;

bool ok(LL t) {
  LL HH[MAX_N]={};
  LL cnt=0;
  REP(i,N) {
    HH[i]=H[i]-B*t;
    if(HH[i]>0) cnt+=(HH[i]+A-B-1)/(A-B);
  }
  return cnt<=t;
}

LL solve() {
  LL good=1e9,bad=0;
  while(abs(good-bad)>1) {
    LL mid=(good+bad)/2;
    (ok(mid)?good:bad)=mid;
  }
  return good;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin>>N>>A>>B;
  REP(i,N) cin>>H[i];

  cout<<solve()<<endl;

  return 0;
}
