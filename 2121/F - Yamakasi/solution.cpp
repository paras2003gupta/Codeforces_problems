//      [TOPIC]     
#include <bits/stdc++.h>
using namespace std;
#define MOD 10e9+7
#define int long long
int gcd(int a, int b){return b==0?a:gcd(b,a%b);}
int mod_add(int a, int b , int m){return ((a%m)+(b%m))%m;}
int mod_sub(int a, int b , int m){return ((a%m)-(b%m)+m)%m;}
int mod_mul(int a, int b , int m){return ((a%m)*(b%m))%m;}
int mod_expo(int a , int b , int m){if(b==0)return 1; int res  = mod_expo(a,b/2,m);    res = mod_mul(res,res,m);if(b%2) res = mod_mul(res,a,m);return res;}
int mod_inverse(int a , int m){    return mod_expo(a,m-2,m);}
int mod_div(int a, int b ,int m){    return mod_mul(a,mod_inverse(b,m),m);}
void printbin(int n){
  for(int i = 30 ; i>=0 ; i--){
        cout<<((n>>i)&1);
   } 
     cout<<endl;
   }
int find_subarrays_with_sum_equal_to_s(vector<int>&arr, int s) {
    if (arr.empty()) return 0;
 
    map<int, int> mp;
    mp[0] = 1;
 
    int sum = 0, ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        ans += mp[sum - s];
        mp[sum]++;
    }
 
    return ans;
}
vector<vector<int>> get_subarrays_whose_max_is_x_or_less(vector<int>& arr, int x) {
    vector<vector<int>> candidate_arrays;
    vector<int> dummy;
 
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > x) {
            if (!dummy.empty()) {
                candidate_arrays.emplace_back(dummy);
                dummy.clear();
            }
        } else {
            dummy.push_back(arr[i]);
        }
    }
 
    // Push the last segment if it's valid
    if (!dummy.empty()) {
        candidate_arrays.push_back(dummy);
    }
 
    return candidate_arrays;
}
 
 
//Seive of Erstodthenes Will return a vector that will contain whether a number is prime or not by bool's value
vector<bool>sieve(int n){vector<bool>prime(n,1);prime[0] = prime[1] = 0;for(int i= 2; i*i< n ;i++){if(prime[i]){for(int j = i*i ; j<n; j+=i){prime[j] = 0;}}}return prime;}
int sub(int x,int y,int mod){int ans = (((x%mod)-(y%mod))%mod);if(ans<0){ans+=mod;}return ans;}
int add(int x,int y,int mod){int ans = (((x%mod)+(y%mod))%mod);if(ans<0){ans+=mod;}return ans;}
signed main(){
ios_base::sync_with_stdio(0);          
cin.tie(0);cout.tie(0);            
int t;cin>>t;
while(t--){
    int n,s,x;
    cin>>n>>s>>x;
    vector<int>a(n);
    for(auto &it:a){
        cin>>it;
    }
    vector<vector<int>>candidate_arrays = get_subarrays_whose_max_is_x_or_less(a,x);
    int ans1 = 0;
    for(auto it:candidate_arrays){
      ans1+=find_subarrays_with_sum_equal_to_s(it,s);
    }
    vector<vector<int>>candidate_arrays1 = get_subarrays_whose_max_is_x_or_less(a,x-1);
    int ans2 = 0;
    for(auto it:candidate_arrays1){
      ans2+=find_subarrays_with_sum_equal_to_s(it,s);
    }
    cout<<ans1-ans2<<endl;
 
    
    
    
      
    
 
}
 
return 0;
}