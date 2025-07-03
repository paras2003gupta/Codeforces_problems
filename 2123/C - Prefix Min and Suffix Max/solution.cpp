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
// -------------------- Binary Search Template(Very basic incomplete template) --------------------
int bs(vi &arr,int target){
    //for first occurence
    int i = 0;
    int j = arr.size()-1;
    while(i<j){
        int m = (i+j+1 /*here +1 denotes we didnt loop in infinite loop*/)/2;
        
        if(arr[m]<=target) i = m;
        if(arr[m]>target) j = m-1;
    }
}
bool pred(int m){
 
}
int alternative_bs(vi &arr,int target){
    int l = -1;
    int r = arr.size();
    while(r-l>1){
        int m  = (l+r)/2;
        pred(m)?l=m:r=m;
    }
    // l will be the last true
    // R will be the first false
    //GARUNTEED
}
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
long long get_hash(string s){
    long long h = 0;
 
    for(int i = 0;i<s.size() ;i++){
        h = (h*31+s[i]-'a'+1)%MOD;
    }
    return h;
}
// -------------------- Solve Function --------------------
void solve() {
    // Your logic here
    int n;cin>>n;
    vi arr(n);
    ai(arr,n);
    vi ans(n,0);
    set<int>st;
    int mini = INT_MAX;
    for(int i = 0;i<n ;i++){
        if(arr[i]<=mini){
            st.insert(arr[i]);
            mini = min(mini,arr[i]);
        }
    }
    int maxi  =INT_MIN;
    for(int i = n-1 ;i>=0 ; i--){
        if(arr[i]>=maxi){
            maxi = max(maxi,arr[i]);
            st.insert(arr[i]);
        }
    }
    for(int i = 0;i<n;i++){
        if(st.find(arr[i])!=st.end()){
            ans[i] = 1;
        }
    }
    for(auto it:ans){
        cout<<it;
    }cout<<endl;
    
    
}
 
// -------------------- Main --------------------
signed main() {
    send help
    int t;cin>>t;
    while (t--) solve();
    return 0;
}