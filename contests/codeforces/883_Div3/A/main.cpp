#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   cin>>T;
   for(int t = 0 ; t < T; t++){
      int n, cont=0;
      cin>>n;

      for(int i = 0 ; i < n; i++){
	    int a,b;
	    cin>>a>>b;
	    cont += (a-b>0);
      }
      cout <<cont<<endl;
   }
   return 0;
}
