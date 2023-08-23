#include <bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   vector<int> data(n, INT_MAX);
   int ans=INT_MAX;
   for(int i = 0; i<n; i++)cin>>data[i];
   //both apart..
   priority_queue<int>q;
   for(int i=0; i < n ; i++){
      q.push(data[i]);
      if(q.size()>2)q.pop();
   }
   int shot1=q.top(); q.pop();
   int shot2=q.top(); q.pop();
   ans = ceil(shot1/2.0)+ceil(shot2/2.0);
   /////two sections one apart
   //one Distance..
   for(int i =0; i+2 < n; i++)
      ans=min(ans, (int)ceil((data[i]+data[i+2])/2.0));
   //both neighbours..
   for(int i = 0 ; i+1 < n; i++){
      int x=max(data[i], data[i+1]), y=min(data[i], data[i+1]);
      //int current=min(x-y, (int)ceil(x/2.0));
      int current=x-y;
      x -=2*current;
      y -=current;
      if(x>0 && y>0) current += ceil((x+y)/3.0);
      else current = ceil((x+2*current)/2.0);
      ans=min(ans, current);
   }
   cout<<ans<<endl;
   return 0;
}
