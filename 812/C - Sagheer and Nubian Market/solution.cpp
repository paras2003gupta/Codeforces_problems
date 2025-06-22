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
 
// The core function to check if 'k' items can be bought within budget 's'
// Returns the total cost if possible, otherwise a very large number (indicating impossible)
int check(int k, const vi& a, int s) {
    if (k == 0) return 0; // If we want to buy 0 items, cost is 0
 
    int n = a.size();
    vector<int> current_costs(n);
    for (int i = 0; i < n; ++i) {
        current_costs[i] = a[i] + (i + 1) * k; // Calculate effective cost for each item
    }
 
    sort(all(current_costs)); // Sort by effective cost
 
    int total_cost = 0;
    for (int i = 0; i < k; ++i) {
        total_cost += current_costs[i];
        if (total_cost > s) { // If at any point cost exceeds budget, it's impossible
            return LLONG_MAX; // Use LLONG_MAX for long long
        }
    }
    return total_cost; // Return the total cost if k items can be bought
}
 
// -------------------- Solve Function --------------------
void solve() {
    int n, s;
    cin >> n >> s;
    vi a(n);
    ai(a, n);
 
    int max_k = 0;
    int min_total_cost = 0;
 
    int lo = 0; // Minimum possible items
    int hi = n; // Maximum possible items
 
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // Number of items we try to buy
 
        int current_possible_cost = check(mid, a, s);
 
        if (current_possible_cost != LLONG_MAX) { // If 'mid' items can be bought
            max_k = mid; // This 'mid' is a possible number of items
            min_total_cost = current_possible_cost; // Store the cost for this 'mid'
            lo = mid + 1; // Try to buy more items
        } else { // 'mid' items cannot be bought
            hi = mid - 1; // Try to buy fewer items
        }
    }
    cout << max_k << " " << min_total_cost << endl;
}
 
// -------------------- Main --------------------
signed main() {
    send help
    int t = 1;
    while (t--) solve();
    return 0;
}