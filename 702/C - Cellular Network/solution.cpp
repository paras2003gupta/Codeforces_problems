#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vi vector<int>
#define all(v) v.begin(), v.end()
 
const int INF = 4e9;
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vi a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
 
    // Optional safety (if input isn't sorted)
    sort(all(a));
    sort(all(b));
 
    auto check = [&](int r) -> bool {
        int i = 0, j = 0;
        while (i < n) {
            // Move tower pointer until we find a tower that might cover city a[i]
            while (j < m && abs(b[j] - a[i]) > r && b[j] < a[i]) {
                ++j;
            }
            // If tower j exists and can cover city i
            if (j < m && abs(b[j] - a[i]) <= r) {
                ++i; // city covered, go to next
            } else if (j > 0 && abs(b[j - 1] - a[i]) <= r) {
                ++i; // previous tower covers this city
            } else {
                return false; // no tower covers city i
            }
        }
        return true;
    };
 
    // Binary Search for minimal r
    int l = 0, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
 
    cout << ans << '\n';
    return 0;
}