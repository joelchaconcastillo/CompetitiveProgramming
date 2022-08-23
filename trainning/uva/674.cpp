#include <bits/stdc++.h>
#define MAXC 5
#define MAXP 8000
using namespace std;
int coin[]={50, 25, 10, 5, 1};
int memo[MAXP*MAXC];
int coin_count(int rem, int id)
{
   if(rem==0) return 1;
   if(id==MAXC) return 0;
   if( rem < 0) return 0;
   if(memo[rem*MAXC+id] != -1) return memo[rem*MAXC+id];
   return memo[rem*MAXC+id] = coin_count(rem, id+1) + coin_count(rem-coin[id], id);
}
int main()
{
  int V;
  memset(memo, -1, sizeof memo);
  while(cin >>V)  cout <<coin_count(V, 0)<<endl;
  return 0;
}
