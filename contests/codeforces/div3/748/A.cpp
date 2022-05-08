#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
      long long a,b,c;
      cin>>a>>b>>c;
      long long m = max(a, max(b,c));
	
      if( a> b && a>c)cout << 0<<" ";
      else if( a<=m)cout << 1+m-a<<" ";

      if( b>a && b>c)cout << 0<<" ";
      else if( b<=m)cout << 1+m-b<<" ";

      if( c>a && c>b)cout << 0<<" ";
      else if( c<=m)cout << 1+m-c<<" ";
      cout <<endl;
   }
}
