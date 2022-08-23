#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t; 
  while(t--)
  {
     int M, l, r, s=0;
     cin >> M;
     vector<pair<int, int> > p2;
     priority_queue<pair<int, int>>pq;
     while(cin >> l>>r)
     {
	if( l == 0 && r == 0) break;
        if( r < s || l > M)continue;
	pq.push(make_pair(-l, -r));
     }
     pq.push(make_pair(-(M+10), -(M+10)));
    while( !pq.empty() && s<M)
    {
	pair<int, pair<int,int>> best(0, pq.top());
	while(! pq.empty() && -pq.top().first <= s)
	{
	   int c = -pq.top().second-s;
	   if( best.first < c) best = make_pair(c, pq.top());
	   pq.pop();
	}
	if(best.first == 0) break;
	p2.push_back(best.second);
        s = -best.second.second;
    }
    if( s<M) cout << "0"<<endl;
    else
    {
       cout << p2.size()<<endl;
       for(auto &i:p2) cout << -i.first<<" " <<-i.second<<endl;
    } 
    if(t>0)
    cout <<endl;
  }
  return 0;
}
