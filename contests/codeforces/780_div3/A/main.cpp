#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
      int a,b;
      cin>>a>>b;
      if(b==0)
	cout<< a+1<<endl;
      else if(a==0) cout<<1<<endl;
      else{
	cout<< a+(2*b)+1<<endl;
      }
   }
   return 0;
}
