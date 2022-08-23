#include <bits/stdc++.h>
using namespace std;
int main(){
   int n,m,q;
   cin>>n>>m>>q;
   vector<string> st(n);
   for(auto &i:st)cin>>i;
   string flat="";
   int sum=0;
   for(int j = 0 ; j < m ; j++)
	for(int i = 0; i < n; i++){
	   flat.push_back(st[i][j]);
	   if(st[i][j]=='*')sum++;
   }
   int ans=count(flat.begin(), flat.begin()+sum, '.');
   int border=sum;
   for(int i = 0; i < q; i++){
      int x,y;
      cin>>x>>y;
      x--,y--;
      int p=y*n+x;
      if(p<border)ans += (flat[p]=='.')?-1:1;
      flat[p]=(flat[p]=='.')?'*':'.';
      if(flat[p]=='*'){
	 if(flat[border]=='.')ans++;
	border++;
      }
      else{
	if(flat[border-1]=='.')ans--;
	border--;
      }
      cout<<ans<<endl;
   }
   return 0;
}
