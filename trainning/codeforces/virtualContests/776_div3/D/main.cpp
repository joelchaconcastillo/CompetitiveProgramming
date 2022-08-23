#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     int n;
     cin>>n;
     vector<int> a(n), pos(n, 0);
     for(auto i=0; i < n; i++)cin>>a[i], pos[a[i]-1]=i;
     vector<int> mv(n);
     for(int i=n-1; i>=0; i--){
	int shift=n-(i-pos[i]);
	mv[i]=shift%n;
	for(auto &j:pos)j=(j+i-pos[i])%n;
	n--;
     }
     for(auto i:mv)cout<<i<<" ";
	cout<<endl;
   }
   return 0;
}
