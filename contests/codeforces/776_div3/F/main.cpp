#include <bits/stdc++.h>
using namespace std;
int n, d, ans=0;
int sol(vector<int> &ex, int ign){
      vector<int> sch;
      for(int i=0; i<=n; i++)
	 if(i!=ign)
	    sch.push_back(ex[i]);
      int minB=INT_MAX, maxB=0;
      for(int i=1; i <sch.size(); i++){
	 minB=min(minB, sch[i]-sch[i-1]-1);
	 maxB=max(maxB, sch[i]-sch[i-1]-1);
      }
      maxB=max((maxB-1)/2, d-sch.back()-1);
      return min(maxB, minB);
}
int main(){
   int T;
   cin>>T;
   while(T--){
      cin>>n>>d;
      vector<int> ex(n+1,0);
      for(int i=1; i<=n;i++)cin>>ex[i];
      pair<int, int> minbreak(d,0);
      for(int i=1; i<=n;i++)
	 minbreak=min(minbreak, {ex[i]-ex[i-1], i});
      ans=sol(ex, minbreak.second);
      if(minbreak.second>1) ans=max(ans, sol(ex, minbreak.second-1));
      cout<<ans<<endl;
   }
   return 0;
}
