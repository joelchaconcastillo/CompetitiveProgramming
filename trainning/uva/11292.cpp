#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, m;
   while(scanf("%d %d\n", &n, &m), n && m)
   {
      vector<int> vH, vK;
      for(int i = 0; i < n; i++)
      {
         int head;
	 scanf("%d\n", &head);
	 vH.push_back(head);
      }
     for(int i = 0; i < m; i++)
      {
         int knight;
	 scanf("%d\n", &knight);
	 vK.push_back(knight);
      }
     sort(vH.begin(), vH.end());
     sort(vK.begin(), vK.end());
     int t = 0;
     int i = 0, j=0;
     for(; i < n && j<m; j++)
     {
	   if( vK[j] >= vH[i] )	
	   {
	      i++;
	      t +=  vK[j];
	   }
     }
     if( i == n ) printf("%d\n", t);
     else printf("Loowater is doomed!\n");

   }
}
