#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
 
    cin >> m;
    vector<int> b(m);
    for (int& x : b) cin >> x;
 
    // Step 1: Combine all throws into one array with team info
    vector<pair<int, int>> all; // {distance, team}
    for (int x : a) all.push_back({x, 0}); // team 0 => A
    for (int x : b) all.push_back({x, 1}); // team 1 => B
 
    // Step 2: Sort by distance
    sort(all.begin(), all.end());
 
    // Step 3: Assume all throws are 3-pointers
    int scoreA = 3 * n;
    int scoreB = 3 * m;
 
    // Track best answer
    int bestA = scoreA, bestB = scoreB;
 
    // Step 4: Iterate and reduce score by 1 for each throw below current d
    for (auto [dist, team] : all) {
        if (team == 0) scoreA--;
        else scoreB--;
 
        // Update best answer
        int currDiff = scoreA - scoreB;
        int bestDiff = bestA - bestB;
        if (currDiff > bestDiff || (currDiff == bestDiff && scoreA > bestA)) {
            bestA = scoreA;
            bestB = scoreB;
        }
    }
 
    // Print result
    cout << bestA << ":" << bestB << endl;
 
    return 0;
}