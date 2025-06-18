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
int find_max_in_array(vector<vector<int>>arr){
  int maxi  = arr[0][0];
    for(auto it:arr){
      for(auto j:it){
        maxi = max(maxi,j);
      }
    }
    return maxi;
}
bool check(vector<pair<int,int>>&p, int r , int c ){
    for(auto it:p){
      if(it.first!=r&&it.second!=c)return false;
    }
    return true;
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
  int n,m;
  cin>>n>>m;
  int maxi  =-1;
  vector<vector<int>>mat(n,vector<int>(m));
  for(int i = 0;i<n ;i++){
      for(int j = 0;j<m ; j++){
          cin>>mat[i][j];
          maxi = max(maxi,mat[i][j]);
      }
  }
  vector<pair<int,int>>p;
  
  for(int i = 0;i<n ;i++){
      for(int j = 0;j<m ; j++){
          if(maxi==mat[i][j]){
            p.push_back({i,j});
          }
      }
  }
  if(p.size()==1){
    cout<<maxi-1<<endl;
    continue;
  }else{
 
    //selecting random 2 points
    int x1 = p[0].first;
    int y1 = p[0].second;
    int x2 = p[1].first;
    int y2 = p[1].second;
    int ans ;
    if(x1==x2){
      int r = x1;
      
      bool flag = true;
      int c = -1;
      for(int i= 0;i<p.size() ;i++){
        if(p[i].first!=r){
          if(c==-1){
            c = p[i].second;
            continue;
          }
          else if(c!=p[i].second){
            flag = false;
            break;
          }
        }
      }
      if(flag){
        cout<<maxi-1<<endl;
      }else{
        cout<<maxi<<endl;
      }
    }
    else if(y1==y2){
      int c = y1;
      
      bool flag = true;
      int r = -1;
      for(int i= 0;i<p.size() ;i++){
        if(p[i].second!=c){
          if(r==-1){
            r = p[i].first;
            continue;
          }
          else if(r!=p[i].first){
            flag = false;
            break;
          }
        }
      }
      if(flag){
        cout<<maxi-1<<endl;
      }else{
        cout<<maxi<<endl;
      }
    
    }
    else{
      if(check(p,x1,y2)||check(p,x2,y1)){
        cout<<maxi-1<<endl;
      }
      else{
        cout<<maxi<<endl;
      }
 
    }
    
  }
  
  
  
 
 
 
 
 
}
    return 0;
}
  
 
  
    
    
             