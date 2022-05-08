#include <bits/stdc++.h>
#define MAXN 1001
#define MAXP 101
#define MAXW 31
using namespace std;
int W[MAXN], P[MAXN], N;
int memo[MAXN*MAXW];
int knapsack(int remW, int id)
{
   if(id == N || remW == 0) return 0;
   if(memo[id*MAXW + remW]!=-1) return memo[id*MAXW + remW];
   if( W[id] > remW )  return knapsack(remW, id+1);
   if( W[id] <= remW ) return memo[id*MAXW + remW] = max(knapsack(remW, id+1), P[id]+knapsack(remW-W[id], id+1));
}
int main()
{
  int T;
  cin >>T;
  while(T--)
  {
    cin >>N;
    for(int i = 0; i < N ; i++) cin >> P[i] >> W[i];

    int NG;
    cin >> NG;
    int summaxprices = 0;
    for(int i = 0; i < NG; i++)
    {
        memset(memo, -1, sizeof memo);
	int G;
	cin >> G;
	summaxprices += knapsack(G, 0);
    }
    cout << summaxprices<<endl; 
  }
  return 0;
}
