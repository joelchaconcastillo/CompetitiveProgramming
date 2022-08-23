#include <bits/stdc++.h>
#define MAX_N 50
using namespace std;
void firstapproach()
{
  int T, N;
  bool M[MAX_N*MAX_N], in[MAX_N], out[MAX_N];
  cin >> T;
  for(int t = 1; t <= T; t++)
  {
     memset(M, 0, sizeof M);
    cin >> N;
	  char c;
    for(int i = 0; i < N ; i++)
    {
	  cin >> c;
	  in[i] = (c=='Y')?1:0;
    }
    for(int i = 0; i < N ; i++)
    {
	  cin >> c;
	  M[i*MAX_N+i]=1;
	  if(c=='Y')
	  {
	     if(i-1 >= 0 ) M[i*MAX_N+ i-1]=in[i-1];
	     if(i+1 < N ) M[i*MAX_N + i+1]=in[i+1];
	  }
    }
    for(int k = 0; k < N ;k++)
    {
       for(int j = 0; j < N ; j++)
	{
    	  for(int i = 0; i < N ; i++)
	  {
		M[i*MAX_N+j] |= (M[i*MAX_N+k] & M[k*MAX_N + j]);
          }
	}
    }
    // 
    cout << "Case #"<<t<<":"<<endl;
    for(int i = 0; i < N; i++)
    {
       for(int j = 0; j < N; j++)
	if( M[i*MAX_N+ j]) cout <<"Y";
	else cout <<"N";
	cout <<endl;
    }
  }
 
}
int main()
{
  int T, N;
  bool M[MAX_N*MAX_N], in[MAX_N], out[MAX_N];
  cin >> T;
  for(int t = 1; t <= T; t++)
  {
     memset(M, 0, sizeof M);
    cin >> N;
	  char c;
    for(int i = 0; i < N ; i++)
    {
	  cin >> c;
	  in[i] = (c=='Y')?1:0;
    }
     for(int i = 0; i < N ; i++)
    {
	  cin >> c;
	  out[i] = (c=='Y')?1:0;
    }

    for(int s = 0; s < N ; s++)
    {
   
	  M[s*MAX_N+s]=1;
       for(int i = s; i < N-1; i++) 
	{
   	   if( !out[i] || !in[i+1]) break;
	
	   M[s*MAX_N+i+1] = 1;
	}
        for(int i = s; i >=1; i--) 
	{
   	   if( !out[i] || !in[i-1]) break;
	   M[s*MAX_N+i-1] =1;
	}
   }
    // 
    cout << "Case #"<<t<<":"<<endl;
    for(int i = 0; i < N; i++)
    {
       for(int j = 0; j < N; j++)
	if( M[i*MAX_N+ j]) cout <<"Y";
	else cout <<"N";
	cout <<endl;
    }
  }
  
  return 0;
}
