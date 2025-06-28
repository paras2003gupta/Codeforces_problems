#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    vector<int> freq(26, 0);
    
    // Count frequency of each character in s
    for (char ch : s) {
        freq[ch - 'a']++;
    }
 
    stack<char> t;
    string u = "";
    
    for (int i = 0; i < n; ++i) {
        char ch = s[i];
        t.push(ch);
        freq[ch - 'a']--;
 
        // Find smallest character remaining in s
        char min_remaining = 'z' + 1;
        for (int j = 0; j < 26; ++j) {
            if (freq[j] > 0) {
                min_remaining = 'a' + j;
                break;
            }
        }
 
        // Pop from stack to u while top <= min_remaining
        while (!t.empty() && t.top() <= min_remaining) {
            u += t.top();
            t.pop();
        }
    }
 
    // Empty remaining characters from stack
    while (!t.empty()) {
        u += t.top();
        t.pop();
    }
 
    cout << u << endl;
    return 0;
}