#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
	 int n;
	 cin>>n;
	 vector<int> a(n, 0);
	 int k=0;
	 for(int i = 1; i <=n; i+=2)
		 for(int j = i; j <=n; j<<=1)
			 a[k++]=j;
	 for(auto i:a)cout <<i<<" ";
	 cout<<endl;

   }
   return 0;
}
