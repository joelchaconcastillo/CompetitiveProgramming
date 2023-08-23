#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &a){
   if(n==1){
     if(a[0]==0)return 0;
     else return 1;
   }
   bool meetCondition=true;
   for(int i = 0 ; i<n/2; i++){
      if(a[i] != a[i+n/2]){
	meetCondition=false;
	break;
      }
   }
   if(meetCondition) return solve(n/2, a);
   for(int i = 0 ; i < n/2; i++)
	  a[i] ^= a[i+n/2];
   return n/2 + solve(n/2, a);
}
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   vector<int> a(n);
   for(int i=0; i<n; i++)
      cin>>a[i];
   cout << solve(n, a)<<endl;
   return 0;
}
