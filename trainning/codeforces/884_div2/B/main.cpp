#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t =1 ; t <= T; t++){
      int n;
      cin>>n;
      vector<bool>isprime(n+1, true);
      isprime[0]=isprime[1]=false;
      vector<int>primes, notprimes={1};
      for(int i = 2; i<=n; i++){
	 if(!isprime[i]){
	   notprimes.push_back(i);
	   continue;
	 }
	 primes.push_back(i);
	 for(int j = 2*i; j <= n; j+=i){
	    isprime[j]=false;
	 }
      }
      vector<int>res;
      int n1 = primes.size()/2, n2 = primes.size(), n3 = notprimes.size();
      swap(notprimes[n3/2], notprimes[0]);
      for(int i = 0 ; i < n1 ;i++) res.push_back(primes[i]);
      for(int i = 0 ; i < n3; i++)res.push_back(notprimes[i]);
      for(int i = n1; i < n2; i++)res.push_back(primes[i]);
      for(auto i:res)cout <<i<<" ";
      cout<<endl;
   }
   return 0;
}
