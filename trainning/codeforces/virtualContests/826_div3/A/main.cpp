#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
      string s1, s2;
      cin>> s1 >>s2;
      int x1=0, x2=0;
      char t1=' ', t2=' ';
      for(auto i:s1){
	  if(i=='X')x1++;
	  else t1=i;
      }
      for(auto i:s2){
	 if(i=='X')x2++;else t2=i;
      }
      if(t1=='S') x1*=-1;
      if(t2=='S') x2*=-1;
      if(t1=='M') x1+=1e4;
      if(t2=='M') x2+=1e4;
      if(t1=='L') x1+=1e5;
      if(t2=='L') x2+=1e5;
      if(x1<x2)cout<<"<"<<endl;
      else if(x1>x2) cout<<">"<<endl;
      else cout<<"="<<endl;

   }
   return 0;
}
