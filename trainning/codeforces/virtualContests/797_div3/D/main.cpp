#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
      int n, k;
      cin>>n>>k;
      string str;
      cin>>str;
      int nW=0, nB=0, l=0, r=k, minv=INT_MAX;
      for(int i=0; i < k; i++) if(str[i]=='B')nB++; else nW++;
      minv = nW;
      while(r<n){
        if(str[r]=='B')nB++;
	else nW++;
	if(str[l]=='B')nB--;
	else nW--;
	minv=min(minv, nW);
	l++, r++;
      }
      cout << minv<<endl;
   }
   return 0;
}
