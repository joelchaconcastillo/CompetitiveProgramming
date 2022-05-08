#include <bits/stdc++.h>
#define N_MAX 1000005
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >>n;
  vector<int> lowestprime(N_MAX+1), primes;
  vector<vector<int> > factors(N_MAX+1), edgelist, adjlist(N_MAX+1);
  primes.push_back(1);
  for(int i = 2;i <= N_MAX; i++)
  {
     if(!lowestprime[i])
     {
       primes.push_back(i);
       for(int j=i;j<=N_MAX; j+=i) lowestprime[j]=i;
     }
     factors[i] = factors[i/lowestprime[i]];
     auto idx = find(factors[i].begin(), factors[i].end(), lowestprime[i]);
     if( idx != factors[i].end()) factors[i].erase(idx);
     else factors[i].push_back(lowestprime[i]);
  }
  vector<vector<pair<int, int>>>adj(N_MAX+1);
  for(int i = 0; i < n; i++)
  {
     int ai;
     cin>>ai;
     if(factors[ai].empty()){cout << 1<<endl; return 0;}
     if(factors[ai].size()==1) factors[ai].push_back(1);
     int f1 = factors[ai][0], f2 = factors[ai][1];
    // edgelist.push_back({f1, f2});
    // adjlist[f1].push_back(i);
    // adjlist[f2].push_back(i);
     adj[f1].push_back({f2,i});
     adj[f2].push_back({f1,i});
  }
  vector<int>dist(N_MAX+1);
  int ans=1e9;
  for(auto i:primes)
  {
	if(i*i>N_MAX)break;
	for(auto j:primes)dist[j]=0;
	queue<pair<int, int> >q;
	for(auto to:adj[i])
	{
	   q.push({to.first, to.second});
	   dist[to.first]=1;
	}
	while(!q.empty())
	{
	  auto current = q.front(); q.pop();
	  for(auto to:adj[current.first])
	  {
	     if( to.second!=current.second)
	     {
		if(!dist[to.first] && to.first!=i) q.push(to), dist[to.first]=dist[current.first]+1;
		else
			ans=min(ans, dist[current.first] + dist[to.first]+1);
	     }
	  }
	}
  }
 // for(auto i:primes)
 // {
 //    if(i*i > N_MAX)break;
 //    for(auto j:primes) dist[j]=0;
 //    queue<pair<int, int> >q;
 //    for(auto info_edge:adjlist[i])
 //    {
 //        q.push({info_edge, edgelist[info_edge][0]==i});
 //        //dist[edgelist[info_edge][0] ^ edgelist[info_edge][1]^i] = 1;
 //        dist[edgelist[info_edge][ edgelist[info_edge][0]==i]] = 1;
 //    }
 //    while(!q.empty())
 //    {
 //       auto current =q.front(); q.pop();
 //       int node = edgelist[current.first][current.second];
 //       for(auto next:adjlist[node])
 //       {
 //          if( next!=current.first)
 //          {
 //              pair<int, int> nextparent(next, edgelist[next][0]==node);
 //              int nextnode = edgelist[nextparent.first][nextparent.second];
 //              if(!dist[nextnode] && nextnode != i) q.push(nextparent), dist[nextnode]=dist[node]+1;
 //              else
 //       	   ans=min(ans, dist[node]+dist[nextnode]+1);
 //          }
 //       }
 //    }
 // }
  if(ans==1e9)cout <<-1<<endl;
  else
   cout << ans<<endl;
  return 0;
}
