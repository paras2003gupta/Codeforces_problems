#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int get_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
 
vector<int> compute_prefix_min(const vector<int>& a) {
    int n = a.size();
    vector<int> pm(n);
    pm[0] = a[0];
    for (int i = 1; i < n; i++) {
        pm[i] = min(pm[i - 1], a[i]);
    }
    return pm;
}
 
vector<int> compute_prefix_sum(const vector<int>& pm) {
    int n = pm.size();
    vector<int> ps(n);
    ps[0] = pm[0];
    for (int i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + pm[i];
    }
    return ps;
}
 
int compute_min_sum(const vector<int>& a, const vector<int>& pm, const vector<int>& ps) {
    int n = a.size();
    const int INF = 4e18;
    int ans = ps[n - 1];
    for (int i = 0; i < n - 1; i++) {
        int prev_min = i > 0 ? pm[i - 1] : INF;
        int prev_sum = i > 0 ? ps[i - 1] : 0;
        int combined = a[i] + a[i + 1];
        int take = min(prev_min, combined);
        ans = min(ans, prev_sum + take);
    }
    return ans;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
 
    vector<int> pm = compute_prefix_min(a);
    vector<int> ps = compute_prefix_sum(pm);
    int result = compute_min_sum(a, pm, ps);
    
    vector<int> dp(n + 1, -1), random(n), used(n), visited(n, 0);
    bool random_flag = false, used_flag = true;
 
    for (int i = 0; i < n; ++i) {
        random[i] = get_rand(1, 100);
    }
 
    cout << result << "\n";
}
 
signed main() {
    fast_io
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}