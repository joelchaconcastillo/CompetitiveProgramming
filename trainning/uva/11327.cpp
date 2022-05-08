#include <bits/stdc++.h>
using namespace std;
int main(){
   int N=1000001;
   vector<long long> phi(N+1), sum_phi(N+1);
   phi[0]=0;
   sum_phi[0]=0;
   sum_phi[1]=2;
   for(int i = 1; i<=N; i++) phi[i]=i;
   for(int i = 2; i<=N; i++){
      if(phi[i]==i){
        for(int j = i; j<=N; j+=i)
	 phi[j] -= phi[j]/i;
      }
   }
   for(int i = 2; i <=N; i++)
	   sum_phi[i]=sum_phi[i-1]+phi[i];
  long long n;
  while(cin>>n, n!=0){
   int idx=lower_bound(sum_phi.begin(), sum_phi.end(), n)-sum_phi.begin();
     int n2=n-sum_phi[idx-1], k=0, i=0;
     while(k<n2){
	if(__gcd(i,idx)==1)k++;
	i++;
     }
   cout << i-1 <<"/"<<idx<<endl;
  }
  return 0;
}
