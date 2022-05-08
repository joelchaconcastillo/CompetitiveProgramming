#include <bits/stdc++.h>
#define MAX_N 100
using namespace std;
int g[MAX_N*MAX_N];

int main()
{
   int ite, N, E, T, M;
   cin >>ite;
   while(ite--)
   {
     fill_n(g, MAX_N*MAX_N, 100000000);
      cin >> N >> E>>T >> M;
      E--;
      for(int i = 0; i < N; i++) g[i*N+i]=0;
      for(int i = 0; i < M ; i++)
      {
	 int a, b,w;
	 cin >> a >>b >> w;
	// cout << a << b << w <<endl;
	 a--, b--;
         g[a*N + b] = w;
      }
      //floyd washall algorithm
      for(int k = 0; k < N; k++) //intermedian nodde..
      {
        for(int i = 0; i < N; i++)
	{
	  for(int j = 0; j < N; j++)
	  {
	      g[i*N+j] = min(g[i*N+j], g[i*N+k] + g[k*N+j]);
	  }
	}
      }
//      for(int i = 0; i < N; i++)
//      {
//       for(int j = 0; j < N ; j++)
//	       cout << g[i*N+j]<< " ";
//       cout <<endl;
//      }
     int c = 0;
     for(int i  =0; i < N; i++) if( g[i*N+E] <= T) c++;
     cout << c<<"\n";
     if(ite)cout<<endl;
   }
   return 0;
}
