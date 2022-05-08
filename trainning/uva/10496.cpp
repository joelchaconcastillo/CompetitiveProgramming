#include <bits/stdc++.h>
#define MAXNB 11
using namespace std;
int A, B, Nbeepers;
int X[MAXNB], Y[MAXNB];
int memo[(1<<11)*MAXNB];
int dist(int c, int d)
{
   return abs(X[c]-X[d]) + abs(Y[c]-Y[d]);
}
int tsp(int visited, int cur)
{
 if(visited == ((1<<(Nbeepers+1))-1)) return dist(cur, 0);
 if( memo[visited*MAXNB + cur] != -1) return memo[visited*MAXNB + cur];
 int mindist = 10000;
 for(int i = 1; i <= Nbeepers; i++)
 {
    if( !((1<<i)&visited ))
    mindist = min( dist(cur, i)+tsp((1<<i)|visited, i), mindist); 
 }
  return memo[visited*MAXNB + cur] = mindist;
}
int main()
{
  int T;
  cin >> T;
  while(T--)
  {
     memset(memo, -1, sizeof memo);
     cin >> A >> B;
     cin >> X[0] >> Y[0];
     cin >> Nbeepers;
     for(int i = 1; i <= Nbeepers; i++)
	cin >> X[i] >> Y[i];
     cout << "The shortest path has length " << tsp(1, 0) <<endl;
  }
  return 0;
}
