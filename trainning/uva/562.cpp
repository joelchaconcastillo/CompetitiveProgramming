#include <bits/stdc++.h>
using namespace std;
#define  MAXR 1010
#define MAXC 50010
bool t[MAXR][MAXC];
int main()
{
 int n;
 scanf("%d\n", &n);
 for(int k = 0; k < n; k++)
 {
    memset(t, false, sizeof t);
//    for(int i = 0; i < MAXR; i++) for(int j=0; j <MAXC; j++) t[i][j]=false;
    int m, v;
    scanf("%d", &m);
    if( m == 0)
    {
	printf("0\n");continue;
    }
    scanf("%d", &v);
    t[0][v] = true;
    for(int i = 1; i < m; i++)
    {
     scanf("%d", &v);
     for(int j = 0; j <= 50000; j++)
	if(t[i-1][j] )
	{
	 t[i][ abs(j - v)] = true;
	 t[i][ j + v] = true;
	}
    }
    int j;
    for(j = 0; j <=50000; j++) if( t[m-1][j] ) break;
    printf("%d\n", j);
 }
 return 0;
}
