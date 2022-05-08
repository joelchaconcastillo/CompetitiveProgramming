#include <bits/stdc++.h>
using namespace std;
//vector< vector< int > > adj;
int dists[200][200];
#define MAXN 1000
int main()
{
 int T;// < 50
 scanf("%d", &T);
// while(T--)
 for(int c = 0; c < T; c++)
 {
 //  memset(dists, 0, sizeof(dists));
   fill_n(*dists, sizeof dists / sizeof **dists, MAXN);

   int N, R; //<= 100
   int s,d;
   scanf("%d", &N);
   scanf("%d", &R);

   for(int i = 0; i < N; i++) dists[i][i] = 0;
   for(int i = 0; i < R; i++)
   {
     int u, v;
     scanf("%d %d", &u, &v); 
     dists[u][v] = 1;
     dists[v][u] = 1;
   }
  scanf("%d %d", &s, &d);

  for(int k = 0 ; k < N; k++)
  { 
   for(int i = 0; i < N; i++)
   {
     for(int j = 0; j < N;j++)
     {
       if( dists[i][k] != MAXN && dists[k][j] != MAXN)
        dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]); 
     }
   }
  }
  int maxv = 0;
  for(int i = 0; i < N; i++)
 { 
 if( dists[s][i] < MAXN && dists[i][d] < MAXN)
  maxv = max(maxv, dists[s][i] + dists[i][d]);
 }
  

  printf("Case %d: %d\n", c+1, maxv);
 }
 return 0;
}
