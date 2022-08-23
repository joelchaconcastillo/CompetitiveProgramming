#include <bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
     int n, k;
     cin>>n>>k;
     long long sum=0; 
     vector<long long> a(n);
     for(int i = 0 ; i < n ; i++)cin>>a[i], sum+= (a[i]/k), a[i]%=k;
     sort(a.begin(), a.end());
     int l = 0, r=n-1;
     while(l<r){
       if(a[l]+a[r] < k) l++;
       else{
	  sum++;
	  r--, l++;
       }
     }
     cout <<sum<<endl;
   }
   return 0;
}
