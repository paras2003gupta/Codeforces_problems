//      [TOPIC]     
#include <bits/stdc++.h>
using namespace std;
#define MOD 10e9+7
#define int long long
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
 
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 585;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
 
int gcd(int a, int b){return b==0?a:gcd(b,a%b);}
int mod_add(int a, int b , int m){return ((a%m)+(b%m))%m;}
int mod_sub(int a, int b , int m){return ((a%m)-(b%m)+m)%m;}
int mod_mul(int a, int b , int m){return ((a%m)*(b%m))%m;}
int mod_expo(int a , int b , int m){if(b==0)return 1; int res  = mod_expo(a,b/2,m);    res = mod_mul(res,res,m);if(b%2) res = mod_mul(res,a,m);return res;}
int mod_inverse(int a , int m){    return mod_expo(a,m-2,m);}
int mod_div(int a, int b ,int m){    return mod_mul(a,mod_inverse(b,m),m);}
void printbin(int n){
  for(int i = 30 ; i>=0 ; i--){
        cout<<((n>>i)&1);
   } 
     cout<<endl;
   }
//Seive of Erstodthenes Will return a vector that will contain whether a number is prime or not by bool's value
vector<bool>sieve(int n){vector<bool>prime(n,1);prime[0] = prime[1] = 0;for(int i= 2; i*i< n ;i++){if(prime[i]){for(int j = i*i ; j<n; j+=i){prime[j] = 0;}}}return prime;}
int sub(int x,int y,int mod){int ans = (((x%mod)-(y%mod))%mod);if(ans<0){ans+=mod;}return ans;}
int add(int x,int y,int mod){int ans = (((x%mod)+(y%mod))%mod);if(ans<0){ans+=mod;}return ans;}
 
 
void solve(){
    int n,k;cin>>n>>k;
    vi a(n);
    ai(a,n);
    vi t(n);
    ai(t,n);
    int garunteed_sum = 0;
    for(int i = 0;i<n ; i++){
        if(t[i]) garunteed_sum+=a[i];
    }
    int to_be_maximised_sum = 0;
    for(int i= 0;i<k ; i++){
        if(!t[i]) to_be_maximised_sum+=a[i];
    }
    int ans = to_be_maximised_sum;
 
    for(int i = k ; i<n ;i++){
        if(!t[i-k]) to_be_maximised_sum-=a[i-k];
 
        if(!t[i]) to_be_maximised_sum+=a[i];
 
        ans = max(ans,to_be_maximised_sum);
 
    }
    cout<<ans+garunteed_sum<<endl;
}
signed main(){
 
ios_base::sync_with_stdio(0);          
cin.tie(0);cout.tie(0);            
int t=1;
while(t--){
    solve();
 
 
}
return 0;
}