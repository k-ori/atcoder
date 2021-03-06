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

 8/4/2018

 13:30-14:30 give up
 14:30-17:00 read editorials

 I tried to count rectangles though, I couldn't move forward AT ALL.

 Editorials:
  - https://atcoder.jp/img/arc071/editorial.pdf
  - https://youtu.be/HAxMNuhoQ3E?t=1813
  - https://eiya5498513.hatenablog.jp/entry/2017/04/09/103728
  - http://hamko.hatenadiary.jp/entry/2017/12/31/165450
  - https://kimiyuki.net/writeup/algo/atcoder/arc-071-d/
  - http://phwinx.hatenablog.com/entry/2017/04/09/003554

 2D -> 1D (independence). Fxck.
 N<=1e5, M<=1e5. That means we MUST solve something for `x` and `y` separtely. Fxck.
 Generally ∑ {a*b : a∈A, b∈B } = ∑{a∈A}*∑{b∈B}.
 Now we want to know ∑{a∈A} for X and Y.

 There are two ways to compute it.
 1. Make N-1 intervals to directly compute ∑{a∈A}
 2. Compute ∑ {x[j]-x[i] : i<j }

 1. compute from N-1 intervals `L`

 We want to know how many times L[i] is added in ∑{a∈A}.
 The interval shows up in all the pairs of left lines and right lines.
 There are i+1 lines in left and N-i lines in right.
 Thus,

  ∑{a∈A} = ∑{(i+1)*(N-i)*L[i] : i=0..N-2 }

 2. Compute from x coordinates

 As seen in #1, line X[i] shows up in positive sign i times (i left lines exist).
 Also it shows up in negative sign N-i-1 times.
 Thus,

  ∑{a∈A} = ∑{(2*i-N+1)*X[i] : i=0..N-1}

 Key:
  - N and M are large. Solve them independently in O(N)
  - Combine result of X and result of Y
  - ∑ {a*b : a∈A, b∈B } = ∑{a∈A}*∑{b∈B}
  - ∑ {x[j]-x[i] : i<j } = ∑ { (2*i-N+1)*x[i] : i=0..N-1 } = ∑ { (i+1)*(N-i-1)*L[i] : i=0..N-2 }

 Summary:
  - Narrow down analysis based on constraint
  - Independence of X and Y in Cartesian coordinate system is SOOOOOOOOOOOOOO typical
  - How many times A[i] shows up? If it's part of pair, we can look at all the possible pairs

 11/27/2020

 5:45-6:00 solve again

 */
const int MOD=1000000007;
//const int MOD=998244353;
struct ModInt {
  unsigned int val;
  ModInt(): val(0) {}
  ModInt(int v) { norm(v%MOD); }
  ModInt(long long v) { norm(v%MOD); }
  ModInt& norm(long long v) {
    v=v<0?v%MOD+MOD:v; // negative
    v=v>=MOD?v-MOD:v; // mod
    val=(unsigned int)v;
    return *this;
  }
  explicit operator bool() const { return val!=0; }
  ModInt operator-() const { return ModInt(0)-*this; }
  ModInt &operator+=(ModInt that) { return norm((long long)val+that.val); }
  ModInt &operator-=(ModInt that) { return norm((long long)val-that.val); }
  ModInt &operator*=(ModInt that) { val=(unsigned long long)val*that.val%MOD; return *this; }
  ModInt &operator/=(ModInt that) { return *this*=that.inv(); }
  ModInt operator+(ModInt that) const { return ModInt(*this)+=that; }
  ModInt operator-(ModInt that) const { return ModInt(*this)-=that; }
  ModInt operator*(ModInt that) const { return ModInt(*this)*=that; }
  ModInt operator/(ModInt that) const { return ModInt(*this)/=that; }
  ModInt pow(long long n) const {
    ModInt x=*this, res=1;
    while(n>0) {
      if(n&1) res*=x;
      x*=x,n>>=1;
    }
    return res;
  }
  ModInt inv() const { return (*this).pow(MOD-2); }
  bool operator==(ModInt that) const { return val==that.val; }
  bool operator!=(ModInt that) const { return val!=that.val; }
  friend ostream& operator<<(ostream& os, const ModInt& that) { return os<<that.val; }
};

// $ cp-batch Sharp3 | diff Sharp3.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address Sharp3.cpp && ./a.out

const int MAX_N=1e5+1;
int N,M;
LL X[MAX_N],Y[MAX_N];

void solve() {
  ModInt toty=0;
  REP(i,M-1) {
    ModInt dy=ModInt(Y[i+1])-Y[i];
    ModInt cnty=ModInt(i+1)*(M-i-1);
    toty+=dy*cnty;
  }

  ModInt res=0;
  REP(i,N-1) {
    ModInt dx=ModInt(X[i+1])-X[i];
    ModInt cntx=ModInt(i+1)*(N-i-1);
    res+=dx*cntx*toty;
  }
  cout<<res<<endl;
}

LL f(vector<LL> ns) {
  LL res=0;
  int L=SZ(ns);
  REP(i,L) res+=((1LL*(i+1)*(L-i)%MOD)*ns[i])%MOD,res%=MOD;
  return res;
}
void solve_length() {
  vector<LL> A(N-1),B(M-1);
  REP(i,N-1) A[i]=X[i+1]-X[i];
  REP(i,M-1) B[i]=Y[i+1]-Y[i];
  LL res=f(A);
  res*=f(B),res%=MOD;
  cout<<res<<endl;
}

LL g(LL Z[MAX_N], int L) {
  LL res=0;
  REP(i,L) res+=1LL*(2LL*i-L+1)*Z[i]%MOD,res%=MOD;
  return res;
}

void solve_org() {
  LL res=g(X,N);
  res*=g(Y,M),res%=MOD;
  cout<<res<<endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin>>N>>M;
  REP(i,N) cin>>X[i];
  REP(i,M) cin>>Y[i];
  solve();
  return 0;
}
