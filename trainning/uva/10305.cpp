#include<bits/stdc++.h>
using namespace std;


int main()
{
 int n,m;
   while(scanf("%d %d", &n, &m) == 2)
  {
    if(n == 0 && m== 0) break; 
    vector<vector<int> >adj(n);
    vector<int> deg(n,0);
    for(int a =0 ; a < m; a++)
    {
      int i, j;
      scanf("%d %d", &i, &j);
      adj[i-1].push_back(j-1);
      deg[j-1]++;
    }
    for(int i = 0; i  < n; i++)
    {
       int node;
       for(int j = 0; j < n; j++)
       {
	 if(deg[j]==0)
         {
	   node = j;
	   break;
         }
       }
      deg[node]=-1;
      for(int j = 0; j < adj[node].size(); j++)
      {
	deg[adj[node][j]]--;
      }
      printf("%d", node+1);
      if(i < n-1) printf(" ");
    }
    printf("\n");
  }
}
