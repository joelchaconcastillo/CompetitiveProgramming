#include <bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
      int n, m;
      cin>>n>>m;
      vector<long long> left(n+1, 0), right(n+1, 0), a(n+1, 0);
      for(int i = 0; i <n; i++)cin>>a[i+1];

      for(int i=2; i<=n; i++)left[i] = left[i-1]+max(0LL, a[i-1]-a[i]);
      for(int i=2; i<=n; i++)right[i] = right[i-1]+max(0LL, a[i]-a[i-1]);
      for(int i = 0 ; i<m; i++){
	 int s,t;
	 cin>>s>>t;
	 if(s<=t)
	  cout<<left[t]-left[s]<<endl;
	 else
	  cout<<right[s]-right[t]<<endl;
      }
   return 0;
}
