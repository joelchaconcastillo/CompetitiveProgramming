#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  scanf("%d\n", &T);
  for(int i = 0; i < T; i++)
  {
     int X;
     scanf("%d\n", &X);
     int P;
     scanf("%d\n", &P); 
     vector<int> vP(P);
     for(int j = 0; j < P; j++)scanf("%d ", &(vP[j]));

     bool found = false;
     for(int k = 0; k < (1<<P) && !found; k++)
     {
	int sum = 0;
        for(int j = 0; j < P && !found; j++)
	{
	   if( k & (1<<j)) sum += vP[j];
	   if( sum == X) found = true;
	}		
     }
     if(found) printf("YES\n"); else printf("NO\n");
  }
}
