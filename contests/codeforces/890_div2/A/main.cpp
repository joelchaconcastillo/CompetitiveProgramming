#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
	 int n;
	 cin>>n;
	 vector<int> a(n);
	 for(auto &i:a)cin>>i;
	 int bignot=0;
	 for(int i =0 ;i+1<n; i++){
		 if(a[i]>a[i+1])bignot = max(bignot, a[i]);
	 }
	 cout << bignot<<endl;
   }
   return 0;
}
