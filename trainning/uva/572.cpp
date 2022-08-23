#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
char adj[MAX_N*MAX_N];
  int n, m;
int c[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int r[] = {1, 1, 1, 0, -1, -1, -1, 0};
void dfs(int i, int j)
{
   if(i < 0 || i >=m || j <0 || j>=n) return;
   if(adj[i*MAX_N + j] == '*') return;
   adj[i*MAX_N + j]='*';
   for( int a = 0; a <8; a++)
      dfs(i+r[a], j+c[a]);
}
int main()
{
  while(cin >>m>>n)
  {
     if(m==0) break;
     for(int i = 0; i < m; i++)
	for(int j = 0; j < n; j++)
	  cin >> adj[i*MAX_N + j];
     int cont = 0;
     for(int i = 0; i < m; i++)
	for(int j = 0; j < n; j++)
	 if(adj[i*MAX_N + j] == '@'){dfs(i,j); cont++;}
     cout << cont <<endl;
  }
  return 0;
}
