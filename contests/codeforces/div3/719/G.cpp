#include <bits/stdc++.h>
#define LONG_MAX 4e18
using namespace std;
int n, m, w;
long long p1[2001*2001], p2[2001*2001], a[2001*2001];
int dx[]={-1, 0, 1, 0}, dy[]={0, -1, 0, 1};
void bfs(long long p[], int startx, int starty)
{
  queue<pair<int, int> >q;
  p[startx*m+starty]=0;
  q.push(make_pair(startx,starty));
  while(!q.empty())
  {
    pair<int, int> node = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) 
    {
      pair<int, int> next(node.first + dx[i], node.second + dy[i]);
      if( next.first < 0 || next.first >=n || next.second <0 || next.second>=m) continue;
      if( a[next.first*m+next.second] ==-1 ) continue;
      if( p[next.first*m+next.second] != LONG_MAX ) continue;
      if( p[next.first*m+next.second]  > p[node.first*m + node.second]+w)
      {
        p[next.first*m+next.second] = p[node.first*m + node.second]+w;
        q.push(next);
      }
    }
  }
}
int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> w;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) cin>>a[i*m+j], p1[i*m+j]=LONG_MAX, p2[i*m+j]=LONG_MAX;
  bfs(p1, 0, 0);
  bfs(p2, n-1, m-1);
  long long best = LONG_MAX;
  if(p1[(n-1)*m + m-1] != LONG_MAX)
     best = p1[(n-1)*m + m-1];
  long long min1=LONG_MAX, min2=LONG_MAX;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
    {
      if(a[i*m+j]>0)
      {
	  if(p1[i*m+j] != LONG_MAX) //is this portal reachable from (0,0) ?
         min1 = min(p1[i*m+j]+a[i*m+j], min1);
	  if(p2[i*m+j] != LONG_MAX) //is this portal reachable from (n,m) ?
         min2 = min(p2[i*m+j]+a[i*m+j], min2);
      }
    }
  best = min(best, min1+min2);
  if(best == LONG_MAX) cout <<"-1"<<endl;
  else
  cout <<best <<endl;
  return 0; 
}
