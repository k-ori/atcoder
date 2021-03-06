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

// $ cp-batch WeLikeAGC | diff WeLikeAGC.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address WeLikeAGC.cpp && ./a.out

/*

 5/9/2019

 16:28-16:55 AC

 https://betrue12.hateblo.jp/entry/2019/03/24/224052
 https://img.atcoder.jp/abc122/editorial.pdf

 6/19/2020

 15:10-15:42 solve again

 */

const int MAX_N=1e2+1;
LL A[MAX_N];
int N;

ModInt dp[MAX_N][4][4][4];

const VV<int> ng={{0,2,1},{2,0,1},{0,1,2}};
ModInt dp[MAX_N][4][4][4];
bool ok(int i, int j, int k) {
  VI a={i,j,k};
  return count(ALL(ng),a)==0;
}
bool ok2(int i, int j, int k) {
  return !(i==0&&j==2&&k==1);
}
void solve() {
  REP(i,4)REP(j,4)REP(k,4) if(ok(i,j,k)) dp[3][i][j][k]=1;
  FOR(i,3,N) REP(j,4) REP(k,4) REP(l,4) {
    REP(m,4) if(ok(k,l,m)&&ok2(j,k,m)&&ok2(j,l,m)) {
      dp[i+1][k][l][m]+=dp[i][j][k][l];
    }
  }
  ModInt res=0;
  REP(i,4)REP(j,4)REP(k,4) res+=dp[N][i][j][k];
  cout<<res<<endl;
}

bool chk(string s) {
  if(s.substr(0,3)=="AGC") return false;
  if(s.substr(1,3)=="AGC") return false;
  return true;
}
void solve_org() {
  string acg="ACGT";
  REP(i,4)REP(j,4)REP(k,4) {
    string x; x+=acg[i],x+=acg[j],x+=acg[k];
    if(x!="AGC"&&x!="GAC"&&x!="ACG") dp[3][i][j][k]=1;
  }
  FOR(i,3,N) REP(c1,4) REP(c2,4) REP(c3,4) REP(c4,4) {
    string x; x+=acg[c1],x+=acg[c2],x+=acg[c3],x+=acg[c4];
    bool ok=chk(x);
    REP(j,3) {
      swap(x[j],x[j+1]);
      ok&=chk(x);
      swap(x[j],x[j+1]);
    }
    if(!ok) continue;
    dp[i+1][c2][c3][c4]+=dp[i][c1][c2][c3];
  }
  ModInt res(0);
  REP(c1,4)REP(c2,4)REP(c3,4) res+=dp[N][c1][c2][c3];
  cout<<res<<endl;
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
