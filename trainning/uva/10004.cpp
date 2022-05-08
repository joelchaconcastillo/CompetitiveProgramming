#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > gr;
int col[300];
bool visited[300];
bool Bi(int node, int c)
{
  visited[node]=true;
  col[node] = c;
  bool flag = true;
  for(int i = 0 ; i < gr[node].size(); i++)
  {
    if(visited[node] && col[gr[node][i]] == col[node] ) flag= false;
   if(!flag) return flag;
    if(!visited[gr[node][i]])
       flag = Bi(gr[node][i], 1-c);
  }
  return flag;
}
int main()
{
  int n,l;
  while(scanf("%d\n", &n), n)
  {
    gr.clear();
    gr.resize(n);
    for(int i = 0; i < n; i++){ col[i] = -1; visited[i]=false;}
    scanf("%d", &l);
    for(int a  = 0; a < l; a++)
    {
      int i, j;
      scanf("%d %d", &i, &j);
      gr[i].push_back(j);
    }
    ;
    if(!Bi(0, 1))
	printf("NOT BICOLORABLE.\n");
    else
	printf("BICOLORABLE.\n");
  }
  return 0;
}
