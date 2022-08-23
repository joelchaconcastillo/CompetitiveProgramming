#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  vector< vector< int > >  adjlist(10000001);
  while(scanf("%d %d\n", &n, &m) != EOF)
  {
     vector<int> used;
     for(int i = 0; i < n; i++)
     {
       int num;
       scanf("%d ", &num);
       adjlist[num].push_back(i+1);
       used.push_back(num);
     }
     for(int i = 0; i < m; i++)
     {
        int k, v;
        scanf("%d %d\n", &k, &v);
	if( adjlist[v].empty() || adjlist[v].size() < k) { printf("0\n"); continue;}
	printf("%d\n", adjlist[v][k-1]);
     }
     for(int i = 0; i < used.size(); i++) adjlist[used[i]].clear();
     

  }
}
