#include <bits/stdc++.h>
using namespace std;
// type alias
typedef long long LL;
typedef pair<int,int> II;
typedef tuple<int,int,int> III;
typedef vector<int> VI;
typedef vector<string> VS;
typedef unordered_map<int,int> MAPII;
typedef unordered_set<int> SETI;
template<class T> using VV=vector<vector<T>>;
// minmax
template<class T> inline T SMIN(T& a, const T b) { return a=(a>b)?b:a; }
template<class T> inline T SMAX(T& a, const T b) { return a=(a<b)?b:a; }
// repetition
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n)  for(int i=0;i<=(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORR(x,arr) for(auto& x:arr)
#define SZ(a) int((a).size())
// collection
#define ALL(c) (c).begin(),(c).end()
// DP
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define ZERO(dp) memset(dp, 0, sizeof(dp))
// stdout
#define println(args...) fprintf(stdout, ##args),putchar('\n');
// debug cerr
template<class Iter> void __kumaerrc(Iter begin, Iter end) { for(; begin!=end; ++begin) { cerr<<*begin<<','; } cerr<<endl; }
void __kumaerr(istream_iterator<string> it) { (void)it; cerr<<endl; }
template<typename T, typename... Args> void __kumaerr(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<"="<<a<<", ",__kumaerr(++it, args...); }
template<typename S, typename T> std::ostream& operator<<(std::ostream& _os, const std::pair<S,T>& _p) { return _os<<"{"<<_p.first<<','<<_p.second<<"}"; }
#define __KUMATRACE__ true
#ifdef __KUMATRACE__
#define dump(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); __kumaerr(_it, args); }
#define dumpc(ar) { cerr<<#ar<<": "; FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }
#define dumpC(beg,end) { cerr<<"~"<<#end<<": "; __kumaerrc(beg,end); }
#else
#define dump(args...)
#define dumpc(ar)
#define dumpC(beg,end)
#endif

// $ cp-batch XORPartitioning | diff XORPartitioning.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address XORPartitioning.cpp && ./a.out

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

/*
 
 5/11/2019
 
 6:20-7:15 give up
 
 5/12/2019
 
 10:15-12:20 read editorials and got AC
 
 https://img.atcoder.jp/diverta2019/editorial.pdf
 http://drken1215.hatenablog.com/entry/2019/05/12/020100
 
 Cumulative XOR is typical way to solve XOR problem in an array.
 XOR of sugsegment is equal <=> _0,X,0,X,..,_XOR{A} walking
 cum XOR `0` affects all X(!=0).
 We are going to group it and solve each `X` separatedly.
 It can be achieved by knapsack dp.
 
 Geneously simple code: https://atcoder.jp/contests/diverta2019/submissions/5353563
 
 */

const int MAX_N=1e6+1;
int A[MAX_N],cum[MAX_N];
int N;

const int MAX_V=(1<<20)+1;
vector<int> P[MAX_V];
ModInt f(int X, int sum) {
  int L=SZ(P[X]);
  if(L==0) return 0;
  ModInt cum2[2]={1,1};
  FOR(i,1,L) {
    int p=P[X][i],cnt0=cum[p]-cum[P[X][i-1]];
    cum2[0]+=cum2[1]*cnt0;
    cum2[1]+=cum2[0];
  }
  return sum==0?cum2[1]:cum2[0];
}
void solve() {
  int sum=0;
  cum[0]=1;
  REP(i,N) {
    sum^=A[i];
    cum[i+1]=cum[i]+(sum==0);
    if(sum!=0) P[sum].push_back(i);
  }
//  dump(sum,cum[N]);
  if(sum!=0) {
    ModInt res=f(sum,sum);
    cout<<res<<endl;
  } else {
    ModInt res=ModInt(2).pow(cum[N]-2);
    FOR(v,1,MAX_V) {
      ModInt x=f(v,sum);
      if(x.val!=0) {
//        dump(v,x);
//        dumpc(P[v]);
      }
      res+=x;
    }
    cout<<res<<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(12)<<fixed;
  
  cin>>N;
  REP(i,N) cin>>A[i];
  solve();
  
  return 0;
}
