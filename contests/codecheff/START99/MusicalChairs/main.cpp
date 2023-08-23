#include <bits/stdc++.h>
using namespace std;
const long long MAXM = 200001, MOD = 1e9+7;
/*
 *   b=5
 *   a^b --->a*a*a*a*a --> (a*a)*(a*a)*a
 *   2^3   2^2    2^1  2^0
 *    0     1      0    1
 *        (a*a)^2       a
 * */
long long binpow(long long a, long long b, long long mod){
    long long res=1;
    a%=mod;
    while(b){
        if(b&1) res=(res*a)%mod;
	b /=2;
	a = (a*a)%mod;
    }
    return res;
}
long long inverse(long long a, long long mod){
   return binpow(a, mod-2, mod);
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   vector<int>inv(MAXM+10, 0);
   inv[1]=1;
   for(int i = 2 ; i < MAXM; i++)
      inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
   while(T--){
     long long N, M, K;
     cin>>N>>M>>K;
     vector<long long> chairs(N);
     vector<long long> L(K);
     for(int i = 0 ; i <N;i++){
	     cin>>chairs[i];
		     chairs[i]--;
     }
     int ii=0;
     vector<bool> marked(N, false);
     for(int i = 0; i < K; i++){
	     cin>>L[i];
	     ii+=L[i];
	     ii%=N;
	     marked[ii]=true;
     }
     vector<long long> cont(N, 0);
     long long ans = 0;
     for(int i = 0; i < N; i++){
	set<long long>bad;
	for(int j = 0 ; j < N; j++){
	   if(!marked[j])continue;
	   bad.insert(chairs[(i+j)%N]);
	}
	long long good = M-bad.size();
	cont[i] = (good*inv[M])%MOD;
	//cont[i] = (good*inverse(M, MOD))%MOD;
	ans = (ans+cont[i]%MOD);
     }
     for(int i = 0 ; i < N; i++){
        long long x, y;
	cin>>x>>y;
	x--, y--;
	ans -=cont[x];
	cont[x]=1;
	for(int j = 0 ; j < N; j++){
	    if(marked[j] && y == chairs[(x+j)%N]){
		    cont[x]=0;
		    break;
	    }
	}
	ans = (ans+cont[x]+MOD)%MOD;
	cout <<ans <<" ";
     }
     cout<<endl;
   }
   return 0;
}
