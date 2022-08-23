#include <bits/stdc++.h>

#define MAX_SIZE 101
using namespace std;

int main()
{
  int N;
  int dp[MAX_SIZE][MAX_SIZE];
  memset(dp, 0, sizeof dp);
  scanf("%d", &N);
//  int **A = new int*[N];
//  for(int i = 0 ; i < N; i++)
//   A[i] = new int[N];
  //reading and pre-computing... 
  for(int i = 0 ; i < N; i++)
  {
    int num;
    for(int j = 0 ; j < N; j++)
     {
       scanf("%d ", &(dp[i][j]));
       if(i > 0 )
       dp[i][j] += dp[i-1][j];
       if(j > 0 )
       dp[i][j] += dp[i][j-1];
       if( i > 0 && j>0)   
       dp[i][j] -= dp[i-1][j-1];
     }
  }
  int max_sum = -100*100*127;
  for(int i = 0; i < N; i++)
  {
    for(int j =0; j < N; j++)
    { 
        for(int a = i; a < N; a++)
        {
	  for(int b = j; b < N; b++)
          { 
	      int sum = dp[a][b];
	      if(i>0) sum -= dp[i-1][b] ;
	      if(j>0) sum -= dp[a][j-1] ;
	      if(i>0 && j>0) sum += dp[i-1][j-1] ;
	      max_sum = max(max_sum, sum);
          }
	}  
    }
  }
  printf("%d\n", max_sum);
  
}

