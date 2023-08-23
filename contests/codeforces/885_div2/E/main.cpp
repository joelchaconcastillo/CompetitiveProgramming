#include <bits/stdc++.h>
const int N = (int) 3e6 + 7;
#define int long long
using namespace std;
/*
     sum_{i=1}^{n-1} f_i + (-i + 1) --> (n-1)*f + n-1 - n(n-1)/2 -> n/2*(2*f+1-(n+1)) --> 2*f-n

     n*f - (n-1)*n/2 --> n*f  n^2/2 - n/2
 ->  (n/2)* (2*f - n + 1) so
     2*f-n+1>0-- 2*f+1 > n


     the answer for coordinate x is the number of odd divisors of x
 * */
int cnt[N+1], inv[N+1], lprime[N+1], P=0, M;
int multiply(int a, int b){
   while(b%M==0){
	b /=M;
	P++;
   }
   return (a*(b%M))%M;
}
int divide(int a, int b){
   while(b%M==0){
      b /=M;
      P--;
   }
   return (a*inv[b%M])%M;
}
int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int x, q;
   cin>>x>>q>>M; 
   int ans = 1;
   //euler method find inverse of mod
   inv[1]=1;
   for(int i=2; i < N && i < M;i++){
       inv[i]=M-inv[M%i]*(M/i)%M;
   }
   //find lowest prime divisor..
   for(int i = 2; i< N; i++){
      cnt[i]=1;
      if(lprime[i]!=0)continue;
      for(int j = i; j <N; j+=i){
	      if(lprime[j]!=0)continue;
	      lprime[j]=i;
      }
   }
   //remove even divisors...
   while(x%2==0) x/=2;
   //product of odd divisors..
   for(int y = 2; y<N; y++){
      if(x%y != 0)continue;
      ans = divide(ans, cnt[y]);
      while(x%y==0){
	x /=y;
	cnt[y]++;
      }
      ans = multiply(ans, cnt[y]);
   }
   //this is in case that x is a prime number
   if(x>2) ans = multiply(ans,2);
   for(int i=0; i<q;i++){
     int xi;
     cin>>xi;
     //remove even dividends
     while(xi%2==0) xi/=2;
     //count numbers..
     while(xi>1){
	  int p=lprime[xi];
	  ans = divide(ans, cnt[p]);
	  while(xi%p==0){
		xi /=p;
		cnt[p]++;
	  }
	  ans = multiply(ans, cnt[p]);
     }
     if(P>0) cout<<0<<endl;
     else cout << ans<<endl;
   }
   return 0;
}
