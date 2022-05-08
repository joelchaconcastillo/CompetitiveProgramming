#include <bits/stdc++.h>
using namespace std;
int main()
{
 int T;
 scanf("%d\n", &T);
 bool row[100], col[100*100];
 for(int t = 0; t< T; t++)
 {
    int N;
    scanf("%d\n", &N);
    long long trace = 0;
    int countrow = 0, countcol=0;
    memset(col, 0, sizeof col);
    for(int i = 0; i < N; i++)
    {
        memset(row, 0, sizeof row);
        bool flagrow=false;
	for(int j = 0; j < N; j++)
	{
          //read value... 
	  int d;
	  scanf("%d ", &d); 
	  if(row[d])flagrow=true;
	  row[d]=true;
          if(col[d])flagcol[] =true;
	  if( i==j ) trace += d;	
	}
	if(flagrow)countrow++;
    }
    if(t>0) printf("\n");
    printf("Case #%d: %lld %d %d", t+1, trace, countrow, countcol);
 }
 return 0;
}
