#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
     set<long long> nums;
     for(long long k=2; k<=1000000; k++){ //check each k<10^6
	long long val = 1+k;
	long long p = k*k;
	for(int cnt = 3 ; cnt <=63; cnt++){
	    val +=p;
	    if(val>1e18) break;
	    nums.insert(val);
	    if(p>(long long)(1e18)/k)break;
	    p *=k;
	}
     }

   for(int t = 1; t<=T; t++){
     long long n;
     cin>>n;
     if(n<=2){
	    cout <<"NO"<<endl;
	    continue;
     }
     long long d = 4*n-3;
     long long sq = sqrt(d);
     long long sqd = -1;

     for(long long i = max(0ll, sq-5); i<=sq+5; i++){
	     if(d == i*i){sqd =i; break;}
     }
     if(sqd!=-1 && (sqd-1)%2 == 0 && (sqd-1)/2>1){
	    cout <<"YES"<<endl;
	    continue;
     }
     if(nums.count(n)>0)cout<<"YES"<<endl;
     else cout <<"NO"<<endl;
   }
   return 0;
}
