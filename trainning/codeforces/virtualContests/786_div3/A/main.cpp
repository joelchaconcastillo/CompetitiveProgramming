#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
      int x, y;
      cin>>x>>y;
      if(y%x != 0){
	 cout<<"0 0"<<endl;
	 continue;
      }

      int a=0,b=0, alpha=y/x;
      if(alpha==1){
	cout<<"1 1"<<endl;
	continue;
      }
      for(int bi=2; bi<=100; bi++){
	 int bai=bi, ai=1;
	 while(bai!=1 && bai<alpha) bai*=bi, ai++;
	 if(bai==alpha){
	    a=ai, b=bi;
	    break;
	 }
      }
      if(a!=0){
	   cout<<a<<" "<<b<<endl;
      }else cout<<"0 0"<<endl;
   }
   return 0;
}
