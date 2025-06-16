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
signed main(){
ios_base::sync_with_stdio(0);          
cin.tie(0);cout.tie(0);            
int t;cin>>t;
while(t--){
     int k,a,b,x,y;
     cin>>k>>a>>b>>x>>y;
     if(y<x){
        swap(x,y);
        swap(a,b);
     }
     int cnt = 0;
     if(k>=a){
        cnt+=(k-a)/x;
        cnt++;
        k-=cnt*x;
     }
     if(k>=b){
        cnt+=(k-b)/y;
        cnt++;
     }
     cout<<cnt<<endl;
}
return 0;
}