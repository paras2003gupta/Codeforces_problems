#include <iostream>
#include <vector>
#include <cstring> // For memset
 
using namespace std;
 
int n1, n2, k1, k2;
const int MOD = 1e8;
 
// memo[i][j][type] stores the result for solve(i, j, type)
long long memo[101][101][2];
 
long long solve(int i, int j, int type) {
    // Base cases
    if (i < 0 || j < 0) return 0;
    if (i == 0 && j == 0) return 1; // 1 way to form an empty arrangement (for recursive calls)
 
    // If the result is already computed, return it
    if (memo[i][j][type] != -1) {
        return memo[i][j][type];
    }
    
    long long ans = 0;
    if (type == 0) { // Ending in a footman
        for (int f = 1; f <= k1; ++f) {
            ans = (ans + solve(i - f, j, 1)) % MOD; // Must come from one ending in a horseman
        }
    } else { // Ending in a horseman
        for (int h = 1; h <= k2 ; ++h) {
            ans = (ans + solve(i, j - h, 0)) % MOD; // Must come from one ending in a footman
        }
    }
 
    // Store the result before returning
    return memo[i][j][type] = ans;
}
 
int main() {
    cin >> n1 >> n2 >> k1 >> k2;
    // Initialize memo table with -1 to indicate "not computed"
    memset(memo, -1, sizeof(memo));
    
    // The final answer for (n1, n2) is the sum of ways ending in footman or horseman
    long long ans = (solve(n1, n2, 0) + solve(n1, n2, 1)) % MOD;
    
    cout << ans << endl;
    return 0;
}