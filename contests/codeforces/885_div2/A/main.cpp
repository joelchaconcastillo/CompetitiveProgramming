#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int T;
   vector<int> r ={0, -1, 0, 1}, c ={-1, 0, 1, 0};
   cin>>T;
   for(int t=1; t<=T; t++){
      int n, m , k, x, y;
      cin>>n>>m>>k>>x>>y;
      x--, y--;
      int color = (x+y)%2;
      bool escaped=true;
      for(int i = 0 ; i < k; i++){
	  int xx, yy;
	  cin>>xx>>yy;
	 xx--, yy--; 
	 if(color == (xx+yy)%2){
		escaped=false;
	 }
      }
      if(escaped)
      cout <<"YES"<<endl;
      else cout <<"NO"<<endl;
   }
   return 0;
}
