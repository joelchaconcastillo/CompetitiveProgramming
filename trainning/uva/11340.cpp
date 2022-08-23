#include <bits/stdc++.h>
#define MAX 150000
using namespace std;
int T[501];
int main()
{
 int N, K, M;
 scanf("%d\n", &N);
 for(int i = 0; i < N; i++)
 {
  for(int l = 0; l < 501; l++) T[l]=0;
//  memset(T, 0, sizeof T);
  double price = 0.0;
  scanf("%d\n", &K);
  for(int j = 0; j < K; j++)
  {
    char c;
    int v;
    scanf("%c %d\n", &c, &v);
    T[c] = v; 
  }
  scanf("%d\n", &M);
  for(int j = 0; j < M; j++)
  {
     char line[MAX];
     fgets(line, MAX, stdin);
     int len = strlen(line);
     for(int k = 0; k < len; k++)
     {
	if( (int)line[k] <= 191 && (int)line[k] >= 32)
        price +=T[line[k]];
     }
  }
  printf("%0.2lf$\n", price/100.0);
 }
 return 0;
}
