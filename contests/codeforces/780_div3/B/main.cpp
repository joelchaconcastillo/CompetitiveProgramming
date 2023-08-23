#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
     int n;
     cin>>n;
     vector<int>data(n);
     for(auto &i:data)cin>>i;
     if(n==1 && data[0] >1){
	cout<<"NO"<<endl;
	continue;
     }
     sort(data.begin(), data.end());
     bool isfea=true;
     if( data[n-1]-data[n-2] > 1) isfea=false;
     if(isfea)cout<<"YES"<<endl;
     else cout << "NO"<<endl;
   }
   return 0;
}
