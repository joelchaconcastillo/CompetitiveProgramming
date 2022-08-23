#include <bits/stdc++.h>
#define MAXN 1e6
using namespace std;
vector<long long> sieve, prime;
void processPrimes(){
    sieve.assign(MAXN+1, 0);
    sieve[1]=1;
    for(long long i = 2; i <= MAXN; i++){
       if(sieve[i]!=0) continue;
       for(long long j = i*i; j <= MAXN; j+=i) sieve[j]=i;
       sieve[i]=i;
       prime.push_back(i);
    }
}
long long binpow(long long a, long long b, long long m){
  long long res=1;
  a%=m;
  while(b){
     if(b&1)res =(res*a)%m;
     a = (a*a)%m;
     b>>=1;
  }
  return res;
}
bool isPrime(long long num){
   if(num<=MAXN)return sieve[num]==num;
   for(auto i:prime)if(num%i==0)return false;
   return true;
}
int main(){
   processPrimes();
   long long a, p;
   while(cin>>p>>a){
     if(p==0 && a==0) break;
     if(binpow(a, p, p)==a && !isPrime(p))
	     cout<<"yes"<<endl;
     else cout <<"no"<<endl;

   }
   return 0;
}
