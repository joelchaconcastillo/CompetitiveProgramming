#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  priority_queue<pair<int, pair<int, int> > > pq; // time, id, periodv
  int id,p;
  while(cin >>s)
  {
     if(s[0]=='#') break;
     cin >>id >>p;
     pq.push(make_pair(-p, make_pair(-id, p))); 
  }
  int np;
  cin>>np;
  for(int i= 0; i < np; i++)
  {
     pair<int, pair<int, int> > c = pq.top();pq.pop();
     cout << -c.second.first<<endl;
     pq.push(make_pair(c.first - c.second.second, c.second)); 
  }
  return 0;
}
