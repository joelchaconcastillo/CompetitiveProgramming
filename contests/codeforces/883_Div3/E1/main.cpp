#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   for(int t = 1; t<=T; t++){
     long long n;
     cin>>n;
     if(n<=2){
	    cout <<"NO"<<endl;
	    continue;
     }
     set<long long> nums;
     for(long long k=2; k<=1000; k++){ //check each k<10^6
	long long val = 1+k;
	long long p = k*k;
	for(int cnt = 2 ; cnt <=20; cnt++){
	    val +=p;
	    if(val>1e6) break;
	    nums.insert(val);
	    p *=k;
	}
     }
     if(nums.count(n)>0)cout<<"YES"<<endl;
     else cout <<"NO"<<endl;
   }
   return 0;
}
