#include <bits/stdc++.h>
using namespace std;
int main(){
   int T;
   cin>>T;
   while(T--){
    int n;
    cin>>n;
    if(n==3)cout<<-1<<endl;
    else{
      if(n%2==0){
	   for(int i= n; i>=1; i--)cout<<i<<" ";
	   cout<<endl;
	}
      else{
        for(int i = n; i> n/2+1; i--)cout<<i<<" ";
	for(int i = 1; i<=n/2+1; i++)cout<<i<<" ";
	cout<<endl;
      }
    }
   }
   return 0;
}
