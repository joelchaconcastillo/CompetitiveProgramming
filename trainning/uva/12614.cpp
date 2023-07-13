#include <bits/stdc++.h>
using namespace std;
int main(){
   int T, N;
   cin>>T;
   for(int t = 1; t<=T; t++){
     cin >> N;
     int tmp = 0, maxv=0;
     for(int i = 0 ; i < N ; i++){
	     cin>>tmp; maxv=max(maxv, tmp);
     }
     cout <<"Case "<<t<<": "<<maxv<<endl;
   }

   return 0;
}
