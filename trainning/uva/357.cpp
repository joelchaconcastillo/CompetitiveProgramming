#include <bits/stdc++.h>
#define MAXN 30001
using namespace std;
int comb[]={1,5,10,25,50};
long mem[5][MAXN];
long dp[MAXN];
long bk(int cur, int rem)
{
  if(rem == 0) return 1;
 if(mem[cur][rem]!=-1) return mem[cur][rem];
 long sum = 0;
 for(int i = cur; i < 5; i++)
 {
  if(rem-comb[i] < 0) continue;
   sum += bk(i,rem-comb[i]);
 }
 return mem[cur][rem] = sum;
}
int main()
{
  int n;
  while(scanf("%d", &n) != EOF)
  {
      memset(dp, 0, sizeof dp); 
      dp[0] = 1;
     for(int i = 0; i < 5; i++)
     {
	for(int j = comb[i]; j < MAXN; j++)
        {
	   dp[j] += dp[j - comb[i]];
        }
     }
//     fill_n(*mem, sizeof mem/ sizeof **mem, -1);
     //long m = bk(0, n);
     long m = dp[n];
     if(m>1)
     printf("There are %ld ways to produce %d cents change.\n", m, n);
     else if(m==1)
     printf("There is only 1 way to produce %d cents change.\n", n);
  }
  return 0;
}

