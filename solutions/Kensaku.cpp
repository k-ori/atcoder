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
 
 8/18/2018
 
 17:45-18:01 got AC
 
 Editorials:
  - https://atcoder.jp/img/yahoo-procon2017-qual/editorial.pdf
  - https://kimiyuki.net/writeup/algo/atcoder/yahoo-procon-2017-qual-c/
  - http://noimin.hatenablog.com/entry/2017/12/25/230134
 
 */

// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG x.cpp && ./a.out
const int MAX_N=1e5+1;
int N,K;
int A[MAX_N]={};
string S[MAX_N];
string solve() {
  if(K==N) return "";
  string T="#";
  REP(i,N) if(A[i]) {
    string s=S[i];
    if(T=="#") {
      T=s;
      continue;
    }
    int j=0;
    while(j<SZ(s)&&j<SZ(T)&&s[j]==T[j]) ++j;
    T=T.substr(0,j);
  }
  int l=0;
  REP(i,N) if(!A[i]) {
    string s=S[i];
    int j=0;
    while(j<SZ(s)&&j<SZ(T)&&s[j]==T[j]) ++j;
    SMAX(l,j);
  }
  if(l>=SZ(T)) return "-1";
  return T.substr(0,l+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>N>>K;
  REP(i,K) {
    int p; cin>>p;
    A[--p]=1;
  }
  REP(i,N) cin>>S[i];
  cout<<solve()<<endl;
  return 0;
}
