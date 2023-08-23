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
	   int cnt1=0;
	   long long s=0;
	   for(int i = 0 ; i < n; i++){
		   cin>>a[i];
		   s+=a[i];
		   cnt1 += (a[i]==1);
	   }
	   if(n==1){
		   cout << "NO"<<endl;
		   continue;
	   }
	   if(s >= cnt1+n){
		   cout << "YES"<<endl;

	   }else cout<<"NO"<<endl;
	   
   }
   return 0;
}
