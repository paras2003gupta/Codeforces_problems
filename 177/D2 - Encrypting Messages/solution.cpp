//      [TOPIC]     
#include <bits/stdc++.h>
using namespace std;
#define MOD 10e9+7
#define int long long
int gcd(int a , int b){         
 if(b==0) return a;
 return gcd(b,a%b);
 }
long long modExp(long long base, long long exp, long long mod) {if (exp == 0) {return 1;}long long half = modExp(base, exp / 2, mod);long long halfResult = (half * half) % mod;if (exp % 2 != 0) { halfResult = (halfResult * base) % mod;}return halfResult;}
void printbin(int n){
  for(int i = 30 ; i>=0 ; i--){
        cout<<((n>>i)&1);
   } 
     cout<<endl;
   }
int add(int x,int y,int mod){
    int ans = (((x%mod)+(y%mod))%mod);
    if(ans<0){
        ans+=mod;
    }
    return ans;
}
int sub(int x,int y,int mod){
    int ans = (((x%mod)-(y%mod))%mod);
    if(ans<0){
        ans+=mod;
    }
    return ans;
}
signed main(){
ios_base::sync_with_stdio(0);          
cin.tie(0);cout.tie(0);            
int t=1;
while(t--){
    int n,m,c;
    cin>>n>>m>>c;
    vector<int>arr(n+1,0);
    for(int i = 0;i< n ;i++){
        cin>>arr[i];
    }            
    vector<int>b(m);
    vector<int>t(n,0);
    for(int i = 0;i<m; i++){
        cin>>b[i];
        t[i] = add(t[i],b[i],c);
        if(n-m+i+1<n)
        t[n-m+i+1] = sub( t[n-m+i+1],b[i],c);
 
    }
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum = add(sum,t[i],c);
        t[i]=sum;
        cout<<add(t[i],arr[i],c)<<" "; 
        
    }
 
 
    
    
    
}
return 0;
}