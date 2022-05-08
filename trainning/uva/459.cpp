#include <bits/stdc++.h>
#define INF 10000
#define MAX_V 100
using namespace std;
void bfs(int s, vector<int> &dist, vector<vector<int> > &adj)
{
   queue<int> q;
   q.push(s);
   dist[s]=0;
   while(!q.empty())
   {
     int u = q.front(); q.pop();
     for(int i = 0; i < adj[u].size(); i++)
     {
       if( dist[adj[u][i]] != INF ) continue;
        q.push(adj[u][i]);
        dist[adj[u][i]]= dist[u]+1;
     }
   }
}
int main()
{
   int N;
   string str;
   cin >> N;
   getline(cin, str);
   getline(cin, str);
   while(N--)
   {
      int maxn;
      getline(cin, str);
      maxn =str[0]-'A';

      vector<vector<int>> adj(maxn+2);
      vector<int> dist(maxn+2, INF);
      while(getline(cin, str))
      {
	if(str.empty()) break;
	adj[str[0]-'A'].push_back(str[1]-'A');
	adj[str[1]-'A'].push_back(str[0]-'A');
      }
      int cont = 0;
      for(int i = 0; i <= maxn; i++)
      {
	if(dist[i] == INF)
	{
	   bfs(i, dist, adj);
	   cont++;
	}
      }
	cout << cont<<endl;
	if(N>0)cout<<"\n";
   }
}

