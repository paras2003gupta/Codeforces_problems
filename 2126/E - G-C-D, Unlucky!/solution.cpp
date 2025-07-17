#include <bits/stdc++.h>
using namespace std;
 
using vi = vector<int>;
 
bool check_prefix_divisibility(const vi& p, int n) {
    for (int i = 2; i <= n; i++) {
        if (p[i - 1] % p[i] != 0) return false;
    }
    return true;
}
 
bool check_suffix_divisibility(const vi& s, int n) {
    for (int i = 1; i < n; i++) {
        if (s[i + 1] % s[i] != 0) return false;
    }
    return true;
}
 
bool check_endpoints(const vi& p, const vi& s, int n) {
    if (__gcd(p[1], s[2]) != s[1]) return false;
    if (__gcd(p[n - 1], s[n]) != p[n]) return false;
    return true;
}
 
bool check_middle_conditions(const vi& p, const vi& s, int n) {
    for (int i = 2; i <= n - 1; i++) {
        int g1 = p[i], g2 = s[i];
        int d = __gcd(g1, g2);
        int l = (g1 / d) * g2;
 
        if (__gcd(p[i - 1], l) != g1) return false;
        if (__gcd(l, s[i + 1]) != g2) return false;
    }
    return true;
}
 
bool is_valid(int n, const vi& p, const vi& s) {
    if (n == 1) return p[1] == s[1];
    if (!check_prefix_divisibility(p, n)) return false;
    if (!check_suffix_divisibility(s, n)) return false;
    if (!check_endpoints(p, s, n)) return false;
    if (!check_middle_conditions(p, s, n)) return false;
    return true;
}
 
void solve() {
    int n;
    cin >> n;
    vi p(n + 2), s(n + 2);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
 
    // Extra vectors and flags
    vector<int> dp(n + 5, -1), used(n + 5, 0), visited(n + 5, 0);
    bool random_flag = false, used_flag = true;
 
    cout << (is_valid(n, p, s) ? "YES" : "NO") << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
 
    return 0;
}