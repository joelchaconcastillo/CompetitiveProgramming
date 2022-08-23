#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
      int count = 0, n;
      cin>>n;
      vector<long long> data(n, 0);
      for(auto &i:data)cin>>i;
      for(int i = n-2; i>=0; i--){
	while(data[i]>=data[i+1] && data[i] != 0) data[i]/=2, count++;
	if(data[i+1] == 0 && data[i]==0){
	   count = -1;
	   break;
	}
      } 
      cout <<count<<endl;
   }
   return 0;
}
