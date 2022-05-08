#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
const int MAXN = 5e5;
long long inv[MAXN], fac[MAXN];

long long extended_euclid(long long a, long long b, long long &x, long long &y){
   if(b==0){
     x=1, y=0;
     return a;
   }
   long long x0, y0, g;
   g = extended_euclid(b, a%b, x0, y0);
   x=y0;
   /**
    *   ax+by=1
    *   (b, a%b)->(b, a-(a/b)*b)
    *   x0*b + y0*(a-(a/b)*b)--> a*y0 + b*(x0-(a/b))
    * */
   y=x0-y0*(a/b);
   return g;
}
long long invmod(long long n, long long m){
    long long x,y,g;
    g = extended_euclid(n, m, x, y); 
    if(x<0)x+=m;
    return x;
}
long long powermod(long long a, long long b, long long m){
   long long res=1;
   while(b){
     if(b&1)  res = (res*a)%m;
     a = (a*a)%m;     
     b>>=1;
   }
   return res;
}
long long comb(long long a, long long b){
   return fac[b]*inv[b-a]%mod*inv[a]%mod;
}
void precal(){
   fac[0]=1;
   inv[0]=invmod(fac[0], mod);
   for(int i = 1; i < MAXN; i++){
     fac[i] = (fac[i-1]*i)%mod;
     inv[i] = invmod(fac[i], mod);
   }
}
int main(){
   int T;
   cin>>T;
   precal();
   while(T--){
     int m,n;
     cin>>m>>n; 
     long long n1Px = powermod(n-1, m-n, mod);
     long long invn1=invmod(n-1, mod);
     long long nPx=1, res=0;
     for(int x = 0; x <= m-n; x++){
	if(x==(m-n)) n1Px=1;
	long long t= comb(n-1, m-x-1)*nPx%mod * n1Px%mod;
        res += t;
	n1Px=(n1Px*invn1)%mod;
	nPx=(nPx*n)%mod;
	res %=mod;
     }
     cout << res<<endl;
   } 
   return 0;
}
