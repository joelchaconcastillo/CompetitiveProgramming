#include <bits/stdc++.h>
using namespace std;
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin>>T;
   for(int i = 1; i <= T; i++){
      int N, M;
      long long sum=0;
      cin>>N>>M;
      for(int j = 0; j < N; j++){
	int t=0;
	cin>>t;
	sum +=t;
      }
      cout<<"Case #"<<i<<": "<< (sum%M)<<endl;
   }
   return 0;
}

