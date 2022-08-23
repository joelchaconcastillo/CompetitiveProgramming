#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   while(cin>>n){
      if(n==0)break;
      int r=sqrt(n-1);
      int d = n-(r*r);
      if((r+1)%2==0){
	if(d<=r+1){
	   cout <<d<<" "<<r+1<<endl;
	}else{
	   d-=r+1;
	   cout << r+1<<" "<<r+1-d <<endl;
	}
      }else{
	if(d<=r+1){
	   cout <<r+1<<" "<<d<<endl;
	}
	else{
	   d-=r+1;
	   cout<<r+1-d<<" " << r+1<<endl;

	}
      }
   }
   return 0;
}
