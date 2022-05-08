#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >>T;
  for(int t = 1; t<=T; t++){
    long long n, sum=0, ans=-1000000;
    cin>>n;
    for(int i = 0; i < n; i++){
	long long d;
	cin>>d;
	sum+=d;
	ans = max(sum, ans);
	if(sum<0)sum=0;
    }
   cout<<"Case #"<<t<<": "<<ans<<"\n";
  }
  return 0;
}
