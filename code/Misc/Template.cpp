// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << " " << H; dbg_out(T...); }

#ifdef SMIE
#define debug(args...) cerr << "(" << #args << "):", dbg_out(args)
#else
#define debug(args...)
#endif

template <typename T> inline T gcd(T a, T b) { T c;while (b) { c = b;b = a % b;a = c; }return a; } // better than __gcd
ll powmod(ll a, ll b, ll MOD) { ll res = 1;a %= MOD;assert(b >= 0);for (; b; b >>= 1) { if (b & 1)res = res * a % MOD;a = a * a % MOD; }return res; }
template <typename T>using orderedSet = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key(k) - number of element strictly less than k
//find_by_order(k) - k'th element in set.(0 indexed)(iterator)

mt19937
rng(chrono::steady_clock::now().time_since_epoch() .count());
//uniform_int_distribution<int>(0, i)(rng)
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);//DON'T CC++
  cin.tie(NULL);//DON'T use for interactive
  int seed = atoi(argv[1]);
}

#define dbg(x) seperator(30,"="),cerr<<#x<<" => "<<endl,dbgg(x),dbgln(),seperator(30,"+"),dbgln()
//#define endl "\n"
ll ceill(ll a,ll b){if(a>=0){if(a%b==0)return a/b;else return a/b+1;}else return a/b;}//Here b>0 for being divisor
ll flr(ll a, ll b){if(a>=0){return a/b;} else {if(a%b==0) return a/b; else return a/b-1;}}//Here b>0 for being divisor
//ll GCD(ll a, ll b){ ll ans=__gcd(a,b);if(ans<0)ans=-ans;return ans;}
ll MOD(ll a, ll b){ if(a>=0) return a%b; else{a=-a; return (b-a%b)%b;}}
template <typename T> void getunique(vector<T>&a){a.resize(unique(a.begin(),a.end())-a.begin());}
void getunique(string& a){a.resize(unique(a.begin(),a.end())-a.begin());}
template <typename T> ll getunique(T* a, T* b){return (unique(a,b)-a);}
ll const mod=1e9+7;//998244353;
const ld PI=acosl(-1.0L);
const ll INF=LLONG_MAX;
//LLONG_MAX=1+2+2^2+2^3+...+2^62=2^63-1; 2^63->Overflow!
//LLONG_MIN=-2^63
ll MOD(ll x){return MOD(x,mod);}
void seperator(ll times, string s){for(ll i=0;i<times;i++)cerr<<s;cerr<<endl;

vector<function<ll(ll,ll)>>MONOID={ADD,MIN,MAX,GCD,LCM,MUL,AND,OR,XOR};
//IDENTITIES of MONOIDS: f(x,identity)=x
vector<ll>Identity={0LL,LLONG_MAX,LLONG_MIN,0LL,1LL,1LL,LLONG_MAX,0LL,0LL};
//----------------------------------------------------------------------------------------------------------
ll SUM(ll* a, ll* b){ll s=0; for(ll i=0;i<b-a;i++)s+=a[i]; return s;}
ll SUM(vector<ll>&a){ll s=0; for(ll i=0;i<a.size();i++)s+=a[i]; return s;}
ll MAX(ll *a, ll *b){ll ans=LLONG_MIN; for(ll i=0;i<b-a;i++)ans=max(ans,a[i]); return ans;}
ll MAX(vector<ll>&a){ll ans=LLONG_MIN; for(ll i=0;i<a.size();i++)ans=max(ans,a[i]); return ans;}
ll MIN(ll *a, ll *b){ll ans=LLONG_MAX; for(ll i=0;i<b-a;i++)ans=min(ans,a[i]); return ans;}
ll MIN(vector<ll>&a){ll ans=LLONG_MAX; for(ll i=0;i<a.size();i++)ans=min(ans,a[i]); return ans;}
ll MEX(vector<ll>a){sort(a.B,a.E); getunique<ll>(a); ll ans=a.size(); for(ll i=0;i<a.size();i++){if(i!=a[i])return ans=i;} return ans;}
bool isSorted(vector<ll>&a,ll asc){for(int i=1;i<a.size()-1;i++){if(asc*(a[i-1]-a[i])>0)return 0;}return 1;}
//----------------------------------------------------------------------------------------------------------
template <typename T> void dbgln(T x);
template <typename T> void dbgg(T x);
template <typename T> void dbgg(T* a, T* b);
template <typename T1,typename T2> void dbgg(pair<T1,T2>pr);
template <typename T> void dbgg(vector<T>v);
template <typename T1, typename T2> void dbgg(map<T1,T2>mp);
template <typename T> void dbgg(set<T>s);
template <typename T> void dbgg(multiset<T>s);
template <typename T> void dbgg(deque<T>d);
template <typename T> void dbgg(queue<T>q);
template <typename T> void dbgg(priority_queue<T>pq);
template <typename T> void dbgg(stack<T>s);
//----------------------------------------------
void dbgln(){ cerr<<endl;}                    
template <typename T> void dbgg(T x) {cerr<<x;}
//----------------------------------------------
template <typename T, typename... Args> void dbgg(const T& x, const Args&... args) { dbgg(x); dbgg(args...);}
template <typename T>void dbgg(T* a, T* b)  { dbgg("[ "); for(int i=0;i<b-a;i++){ dbgg(a[i]); if(i<b-a-1)dbgg(", "); } dbgg(" ]");dbgln();}
template <typename T1,typename T2> void dbgg(pair<T1,T2>pr) { dbgg("(");dbgg(pr.F);dbgg(",");dbgg(pr.S);dbgg(")");dbgln();}
template <typename T> void dbgg(vector<T>v)  {dbgg("[ ");for(int i=0;i<v.size();i++){dbgg(v[i]);if(i<v.size()-1)dbgg(", ");} dbgg(" ]");dbgln();}
template <typename T1, typename T2> void dbgg(map<T1,T2>mp) { dbgg("{ "); for(auto it=mp.B;it!=mp.E;++it){ dbgg("(");dbgg(it->F);dbgg(" -> ");dbgg(it->S);dbgg(")"); if(next(it)!=mp.E){dbgg(","),dbgln();}} dbgg(" }");dbgln();}
template <typename T> void dbgg(set<T>s) { dbgg("{ "); for(auto it=s.B;it!=s.E;it++){dbgg(*it);if(next(it)!=s.E)dbgg(", ");} dbgg(" }");dbgln();}
template <typename T> void dbgg(multiset<T>s) { dbgg("{ "); for(auto it=s.B;it!=s.E;it++){dbgg(*it);if(next(it)!=s.E)dbgg(", ");} dbgg(" }");dbgln();}
template <typename T> void dbgg(deque<T>d) {dbgg("[ ");for(int i=0;i<d.size();i++){dbgg(d[i]);if(i<d.size()-1)dbgg(", ");} dbgg(" ]");dbgln();}
template <typename T> void dbgg(queue<T>q) {dbgg("[ ");while(!q.empty()){dbgg(q.front());q.pop();if(!q.empty())dbgg(", ");} dbgg(" ]");dbgln();}
template <typename T> void dbgg(priority_queue<T>pq) {dbgg("[ ");while(!pq.empty()){dbgg(pq.top());pq.pop();if(!pq.empty())dbgg(", ");} dbgg(" ]");dbgln();}
template <typename T> void dbgg(stack<T>s) {dbgg("[ ");while(!s.empty()){dbgg(s.top());s.pop();if(!s.empty())dbgg(", ");} dbgg(" ]");dbgln();}