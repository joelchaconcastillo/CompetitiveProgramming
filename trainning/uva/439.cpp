#include <bits/stdc++.h>
#define MAXN 8
using namespace std;
bool valid(int offset_r, int offset_c, int current)
{
  if( offset_r + current/MAXN >= 8  || offset_r + current/MAXN < 0) return false;
  if( offset_c + current%MAXN >= 8  || offset_c + current%MAXN < 0) return false;
  return true;
}
 int main()
{
  char sc[3], tc[3];
  int ro[]={-2, -1, 1, 2, 2,1, -1, -2};
  int co[]={1, 2, 2, 1, -1,-2, -2, -1};
  while(cin >> sc >> tc)
  {
     int s = (sc[0]-'a')*MAXN + sc[1]-'0'-1, t = (tc[0]-'a')*MAXN + tc[1]-'0'-1;
     vector<int> d(MAXN*MAXN, -1000000);
     priority_queue<pair<int, int>> pq;
     d[s] = 0;
     pq.push(make_pair(0, s));
    while(!pq.empty())
    {
       pair<int, int> c = pq.top(); pq.pop();
       for(int i = 0; i < 8; i++)
       {
          if(!valid(ro[i], co[i], c.second)) continue;
           pair<int, int> next(c.first-1, c.second+ro[i]*MAXN + co[i]);
	  // cout << next.first<<  " "<<c.second/MAXN <<","<<c.second%MAXN<<" "<<next.second/MAXN <<","<<next.second%MAXN<<endl;
	  if( d[next.second]  < next.first )
	  {
	
	     d[next.second] = next.first;
	     pq.push(next);
 	  }
       } 
    }  
    cout <<"To get from "<<sc<<" to "<<tc<<" takes "<< -d[t]<<" knight moves."<<endl;
  }
  return 0;
}
