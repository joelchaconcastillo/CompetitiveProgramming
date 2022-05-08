#include <bits/stdc++.h>
using namespace std;

bitset<30> rw, ld, rd;
char board[30][30];
int counter, N;

void bk(int c)
{
   if(c == N)
   {
      counter++;
      return;
   }
   for(int r = 0; r < N; r++)
   {
      if(board[r][c] != '*' && !rw[r] && !ld[r-c+N-1] && !rd[r+c] )
      {
         rw[r] = ld[r-c+N-1]  = rd[r+c] =true;
	 bk(c+1);
         rw[r] = ld[r-c+N-1]  = rd[r+c] =false;
      }
   }
}

int main()
{
	int caseT = 0;
      while(scanf("%d\n", &N), N)
      {
	for(int i = 0; i < N; i++)
	  for(int j = 0; j < N; j++) scanf("%c ", &(board[i][j]));
	rw.reset();
	ld.reset();
	rd.reset();
	counter = 0;
	bk(0);
	printf("Case %d: %d\n", ++caseT, counter);
      }
}
