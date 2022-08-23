#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
     int n;
     cin>>n;
     vector<int> a(n), b(n), res(n,0);
     for(auto &i:a)cin>>i;
     for(auto &i:b)cin>>i;
     cout << b[0]-a[0] <<" ";
     for(int i = 1 ; i < n; i++){
	cout << b[i]-max(a[i], b[i-1])<<" ";
     }
     cout<<endl;
   }
   return 0;
}
