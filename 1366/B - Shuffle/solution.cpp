#include <bits/stdc++.h>
using namespace std;
 
// -------------------- Type Definitions --------------------
#define int long long
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
// -------------------- Constants --------------------
const ll MOD = 1e9 + 7;
const lld PI = 3.14159265358979323846;
const ll template_array_size = 1e6 + 585;
 
// -------------------- Fast IO --------------------
#define send ios_base::sync_with_stdio(false);
#define help cin.tie(NULL); cout.tie(NULL);
 
// -------------------- Macros --------------------
#define f0r(i, n) for (int i = 0; i < (n); ++i)
#define f1r(i, a, b) for (int i = (a); i < (b); ++i)
#define f0rd(i, n) for (int i = (n); i >= 0; --i)
#define f1rd(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define getunique(v) { sort(all(v)); v.erase(unique(all(v)), v.end()); }
#define ai(a, n) f0r(i, n) cin >> a[i];
#define ao(a, n) f0r(i, n) { if (i) cout << " "; cout << a[i]; } cout << '\n';
 
// -------------------- Debugging --------------------
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for (int i = 0; i < v.size(); i++) { if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.f << ", " << p.s << ")";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first >> p.second; return cin;
}
 
// -------------------- Random --------------------
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// -------------------- File IO --------------------
void usaco(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}
 
// -------------------- Modular Arithmetic --------------------
int mod_add(int a, int b, int m) { return ((a % m) + (b % m)) % m; }
int mod_sub(int a, int b, int m) { return ((a % m) - (b % m) + m) % m; }
int mod_mul(int a, int b, int m) { return ((a % m) * (b % m)) % m; }
int mod_expo(int a, int b, int m) {
    if (b == 0) return 1;
    int res = mod_expo(a, b / 2, m);
    res = mod_mul(res, res, m);
    if (b % 2) res = mod_mul(res, a, m);
    return res;
}
int mod_inverse(int a, int m) { return mod_expo(a, m - 2, m); }
int mod_div(int a, int b, int m) { return mod_mul(a, mod_inverse(b, m), m); }
 
// -------------------- Misc Utilities --------------------
void printbin(int n) {
    f0rd(i, 30) cout << ((n >> i) & 1);
    cout << '\n';
}
vector<bool> sieve(int n) {
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}
bool isIntersect(pii a, pii b){
    int x1 = a.f;
    int y1 = a.s;
    int x2 = b.f;
    int y2 = b.s;
    if(x2>y1||x1>y2){
        return false;
    }
    return true;
}
pii doUnion(pii a , pii b){
    int x1 = a.f;
    int y1 = a.s;
    int x2 = b.f;
    int y2 = b.s;
    pii ans;
    ans.f = min(x1,x2);
    ans.s = max(y1,y2);
    return ans;
}
// -------------------- Solve Function --------------------
void solve() {
    // Your logic here
    int n,x,m;
    cin>>n>>x>>m;
    pii init_range = make_pair(x-1,x-1);
    
    // cout<<init_range.f<<" "<<init_range.s<<" "<<endl;
    for(int i = 0;i<m ; i++){
        int l,r;cin>>l>>r;
        l--,r--;
        pii newpair = make_pair(l,r);
        if(isIntersect(newpair,init_range)){
            init_range = doUnion(newpair,init_range);
        }
        // cout<<init_range.f<<" "<<init_range.s<<" "<<endl;
    }
    cout<<init_range.s-init_range.f+1<<endl;
}
 
// -------------------- Main --------------------
signed main() {
    send help
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}