#include <bits/stdc++.h>
using namespace std;
int main(){
   int t,n;
   cin>>t;
   while(t--){
     cin>>n;
     vector<long long >data(n);
     long long currentsum=0;
     for(int i = 0; i < n ; i++){
	     cin>>data[i];
	     currentsum+=data[i];
     }
     for(int i = 0;i+1 < n; i++){
	for(int j =i+1; j < n; j++){
	   int ai=data[i], aj=data[j];
	   int Or=ai|aj;
	   if(ai+aj < Or)continue;
	   data[i]=0;
	   data[j]=Or;
	}
     }
     currentsum=0;
     for(auto i:data)currentsum+=i;
     cout << currentsum<<endl;
   }
   return 0;
}
