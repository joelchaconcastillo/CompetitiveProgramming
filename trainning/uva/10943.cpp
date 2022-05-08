#include<bits/stdc++.h>
#define MAXN 101
#define MAXK 101
using namespace std;
int memo[MAXN*MAXK];
int maxnumber = 1000000;
int count(int n, int k)
{
   if( k == 1) return 1;
   if(memo[n*MAXK+k]!= -1) return memo[n*MAXK+k];
   int sum = 0;
   for(int x = 0; x <= n; x++)
      sum +=count(n-x, k-1)%maxnumber;
   sum %=maxnumber;
   return  memo[n*MAXK+k] = sum;
}
int main()
{
  int N,K;
  while( cin >> N >> K)
  {
     memset(memo, -1, sizeof memo);
     if( N==0 && K==0) break;
     cout << count(N, K)<<endl;
  }
  return 0;
}
