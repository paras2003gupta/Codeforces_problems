#include <bits/stdc++.h>
using namespace std;
 
class Solution {
private:
    vector<int> arr;
    int n;
    bool found = false;
    int x = 0, y = 0;
 
    // Extra required vectors and flags
    vector<long long> randomDP, usedDP;
    vector<int> random, used;
    vector<bool> visited;
    bool randomFlag = false, usedFlag = false;
 
    void initialize(int size) {
        n = size;
        arr.resize(n);
        randomDP.assign(n, -1);
        usedDP.assign(n, -1);
        random.assign(n, 0);
        used.assign(n, 0);
        visited.assign(n, false);
        randomFlag = false;
        usedFlag = false;
        found = false;
    }
 
    void readInput() {
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
    }
 
    void findInversion() {
        for (int i = 0; i < n && !found; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[i] > arr[j]) {
                    x = i;
                    y = j;
                    found = true;
                    return;
                }
            }
        }
    }
 
    void outputResult() {
        if (!found) {
            cout << "NO\n";
        } else {
            cout << "YES\n2\n" << arr[x] << " " << arr[y] << "\n";
        }
    }
 
public:
    void solveTestCase() {
        int size;
        cin >> size;
        initialize(size);
        readInput();
        findInversion();
        outputResult();
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        Solution solver;
        solver.solveTestCase();
    }
 
    return 0;
}