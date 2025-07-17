#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const long long INF = 4e18; // A large value representing infinity
 
int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, l, k;
    cin >> n >> l >> k;
 
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    // dp[i][j] = min time to reach sign 'i' with 'j' removals
    vector<vector<long long>> dp(n, vector<long long>(k + 1, INF));
 
    // Base case: Start at sign 0 with 0 removals and 0 time
    dp[0][0] = 0;
 
    // Fill the DP table (This part was correct)
    for (int i = 1; i < n; ++i) {
        for (int p = 0; p < i; ++p) {
            int removed_count = i - p - 1;
            long long time_segment = (long long)(d[i] - d[p]) * a[p];
            for (int j = removed_count; j <= k; ++j) {
                if (dp[p][j - removed_count] != INF) {
                    dp[i][j] = min(dp[i][j], dp[p][j - removed_count] + time_segment);
                }
            }
        }
    }
    
    long long min_total_time = INF;
 
    // ----- CORRECTED FINAL ANSWER CALCULATION -----
    // Consider each sign 'i' as the potential *last kept sign* on the route.
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            // Number of signs that MUST be removed after sign 'i'
            int removals_after = (n - 1) - i;
            
            // Check if the total removals are within the allowed limit 'k'
            if (j + removals_after <= k) {
                // If state (i, j) is reachable
                if (dp[i][j] != INF) {
                    long long final_leg_time = (long long)(l - d[i]) * a[i];
                    min_total_time = min(min_total_time, dp[i][j] + final_leg_time);
                }
            }
        }
    }
 
    cout << min_total_time << endl;
 
    return 0;
}