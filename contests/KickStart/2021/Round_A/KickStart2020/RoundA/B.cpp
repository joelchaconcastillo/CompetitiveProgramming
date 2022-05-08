#include <bits/stdc++.h>
#define MAX_N 50
#define MAX_K 31
#define MAX_P 50*31
using namespace std;
int C[MAX_N*MAX_K], memo[MAX_K*MAX_P];
int table[MAX_N*MAX_P];
int N,K,P;
int BK(int rem, int item, int cost)
{
  if(rem<0 ) return -10000;
  if(item == N )return cost;
   if(memo[item*MAX_K+rem]>0 ) return memo[item*MAX_K+rem];
   int maxv = 0;
   for(int i = 0; i <= K; i++)
   {
     int v =cost+BK(rem-i, item+1, C[item*MAX_K + i]);
	cout << item << ","<<i<<","<<rem-i<<","<<v<<","<<cost<<endl;
     maxv = max(maxv, v);
   }
  return memo[item*MAX_K +rem] = maxv;
}
int dp()
{
   for(int i = 1; i <= K ; i++) table[i]=C[i];
   for(int i = 1; i < N ; i++)
   {
      for(int j = 0; j <= P; j++)
      {
	for(int k = 0; k <= min(K, j); k++)
	{
	   table[i*MAX_P + j] = max(table[i*MAX_P+j], C[i*MAX_K + k]+table[(i-1)*MAX_P+j-k]);
	}
      }
   }
  return table[(N-1)*MAX_P+P];
}
int main()
{
  int T;
  cin >> T;
  for(int i = 1; i <=T; i++)
  {
    cin >> N >> K >> P;
    memset(C, 0, sizeof C);
    //memset(memo, 0, sizeof memo);
    memset(table, 0, sizeof table);
    for(int j = 0; j < N ; j++)
    {
	int sum=0;
	for(int z = 1; z <= K; z++)
	{
	   int tt;
	   cin >> tt;	
	   sum += tt;
	   C[j*MAX_K + z] = sum;
	}
    }
//     cout << "Case #"<<i<<": \n"<<BK(P, 0, 0)<<endl;
     cout << "Case #"<<i<<": "<<dp()<<endl;
  }
  return 0;
}
