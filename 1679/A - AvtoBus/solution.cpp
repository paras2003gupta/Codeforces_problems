//      [TOPIC]     
#include <bits/stdc++.h>
using namespace std;
#define MOD 10e9+7
#define int long long
int gcd(int a, int b){return b==0?a:gcd(b,a%b);}
int lcm(int a , int b ){return ((a*b)/gcd(a,b));}
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
//Seive of Erstodthenes Will return a vector that will contain whether a number is prime or not by bool's value
vector<bool>sieve(int n){vector<bool>prime(n,1);prime[0] = prime[1] = 0;for(int i= 2; i*i< n ;i++){if(prime[i]){for(int j = i*i ; j<n; j+=i){prime[j] = 0;}}}return prime;}
int sub(int x,int y,int mod){int ans = (((x%mod)-(y%mod))%mod);if(ans<0){ans+=mod;}return ans;}
int add(int x,int y,int mod){int ans = (((x%mod)+(y%mod))%mod);if(ans<0){ans+=mod;}return ans;}
signed main(){
ios_base::sync_with_stdio(0);          
cin.tie(0);cout.tie(0);            
int t;cin>>t;
while(t--){
  int n;cin>>n;
  if(n<4){
    cout<<-1<<endl;
    continue;
  }
  if(n%2!=0){
    cout<<-1<<endl;
    continue;
  }
 
  int ans = n/12;
  int rem = n%12;
  int mini = ans*2;
  int maxi = ans*3;
  if(rem==4||rem==6){
    mini+=1;
    maxi+=1;
  }
  else if(rem==10||rem==8){
    mini +=2;
    maxi+=2;
  }
  else if(rem==2){
    mini+=1;
  }
  cout<<mini<< " "<<maxi<<endl;
  
}
return 0;
}