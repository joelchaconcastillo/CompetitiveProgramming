#include <bits/stdc++.h>
using namespace std;
int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   int T;
   cin>>T;
   while(T--){
	  int a, b, c;
	  cin>>a>>b>>c;
	  int minv = min(a,b);
	  if(c%2!=0) a++;
	  a -=minv; b-=minv;
	  if(a>b)cout <<"First"<<endl;
	  else if(b>a)cout<<"Second"<<endl;
	  else cout << "Second"<<endl;

   }
   return 0;
}
