#include <bits/stdc++.h>
using namespace std;
int Prices[30][30];
int Mem[300][30];
int NModels[30];
int Money, NGarments;	
int WS(int M, int idx)
{
   if( M < 0) return -100000000;
   if( NGarments == idx ) return Money - M;
   if( Mem[M][idx] != -1 ) return Mem[M][idx];
   int maxv = -1;
   for(int i = 0; i < NModels[idx]; i++)
	maxv = max(maxv, WS(M-Prices[idx][i], idx+1));

   return Mem[M][idx] = maxv;
}
int main()
{
   int N;
   scanf("%d\n", &N);
   while(N--)
   {
      scanf("%d %d\n",&Money, &NGarments);
      for(int i = 0; i < NGarments; i++)
      {
	scanf("%d ", NModels+i);
	for(int j = 0; j < NModels[i]; j++)
	{
		scanf("%d ", &(Prices[i][j]));
	}
      }
      memset(Mem, -1 ,sizeof Mem);
      int sc = WS(Money, 0);
      if(sc < 0) printf("no solution\n");
      else printf("%d\n", sc);
   }
}
