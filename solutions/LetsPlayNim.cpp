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

// $ cp-batch LetsPlayNim | diff LetsPlayNim.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address LetsPlayNim.cpp && ./a.out

/*

 10/11/2020

 7:33-8:10 WA

 10/14/2020

 9:05-9:40, 23:17-24:17 AC

 https://twitter.com/hanseilimak/status/1316637571040993280
 https://docs.google.com/document/d/1Yq384PEooRVsmlzB103YMLWwE_JhPN8AbxZagNrF_vY/edit#bookmark=id.e2qwfqmompy9

 https://atcoder.jp/contests/arc105/editorial/171
 https://youtu.be/dhhldocM--0?t=1750

 https://twitter.com/kzyKT_M/status/1315308874274992129
 https://twitter.com/camypaper/status/1315310110239985664
 https://twitter.com/laycrs/status/1315312706526744577
 https://twitter.com/tomerun/status/1315309049181728769
 https://twitter.com/drken1215/status/1315309442955505670
 https://twitter.com/tanakh/status/1315320874757550087
 https://twitter.com/ajis_ka/status/1315310047799373827
 https://kmjp.hatenablog.jp/entry/2020/10/12/0930

 */

const int MAX_N=1e6+1;
LL A[MAX_N];
int N;

void solve() {
  if(N%2==0) {
    map<int,int> cnt;
    REP(i,N) cnt[A[i]]++;
    bool alle=true;
    FORR(kvp,cnt) alle&=(kvp.second%2)==0;

    cout<<(alle?"Second":"First")<<endl;
  } else {
    cout<<"Second"<<endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(12)<<fixed;

  int t; cin>>t;
  while(t--) {
    cin>>N;
    REP(i,N) cin>>A[i];
    solve();
  }

  return 0;
}
