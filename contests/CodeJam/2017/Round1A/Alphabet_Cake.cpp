#include <bits/stdc++.h>
#define N 30
using namespace std;
char g[N*N];
int R,C;
int main()
{
  int ite;
  cin>>ite;
  for(int t = 1; t<=ite;t++)
  {
     cin >> R>>C;
     for(int i=0;i<R;i++)
      for(int j=0; j<C; j++)cin >> g[i*C+j];

     for(int i=0;i<R;i++)
     {
      for(int j=0; j<C; j++) 
      {
	      if(g[i*C+j]!='?')
	      {
		      int k=j-1;
		  while(k>=0 && g[i*C+k]=='?') g[i*C+k]=g[i*C+j], k--;
		  k=j+1;
		  while(k<C && g[i*C+k]=='?') g[i*C+k]=g[i*C+j], k++;
	      }
      }
     }
     for(int i=0;i<R;i++)
     {
      for(int j=0; j<C; j++) 
      {
	      if(g[i*C+j]!='?')
	      {
		  int k=i-1;
		  while(k>=0 && g[k*C+j]=='?') g[k*C+j]=g[i*C+j], k--;
		  k=i+1;
		  while(k<R && g[k*C+j]=='?') g[k*C+j]=g[i*C+j], k++;
	      }
      }
     }
     cout << "Case #"<<t<<":\n";
     for(int i=0; i < R;i++)
     {
	for(int j=0; j <C;j++)
		cout << g[i*C+j];
	cout <<"\n";
     }

  }
  return 0;
}
