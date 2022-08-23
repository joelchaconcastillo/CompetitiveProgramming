#include <bits/stdc++.h>
#define MAX_R 1000
#define MAX_C 1000
using namespace std;
int g[MAX_R*MAX_C], topp[MAX_R*MAX_C], leftt[MAX_R*MAX_C], bottomm[MAX_R*MAX_C], rightt[MAX_R*MAX_C];
int count(int vertical, int horizontal)
{
  return max(0,min(vertical/2, horizontal) + min(vertical, horizontal/2)-2); 
}
int main()
{
  int ite;
  cin>>ite;
  for(int t =1 ;  t<=ite; t++)
  {
    int R, C;
    cin>>R>>C;
    for(int i = 0; i < R; i++)
    {
      for(int j = 0; j < C; j++)
      {
	cin >> g[i*C+j];
	topp[i*C+j]=0;
	leftt[i*C+j]=0;
	bottomm[i*C+j]=0;
	rightt[i*C+j]=0;
      }
    }
    for(int i = 0; i < R; i++)
    {
      for(int j = 0; j < C; j++)
      {
	if(g[i*C+j]==0)continue;
	if(i==0) topp[i*C+j] = 1;
	else topp[i*C+j] = topp[(i-1)*C+j]+1;
	if(j == 0) leftt[i*C+j] =1;
	else leftt[i*C+j] = leftt[i*C+j-1]+1;
      }
    }


    for(int i = R-1; i >=0; i--)
    {
      for(int j = C-1; j >=0; j--)
      {
	  if( g[i*C+j] == 0 ) continue;
	  if( i == R-1 ) bottomm[i*C+j]=1;
          else bottomm[i*C+j]=bottomm[(i+1)*C+j] + 1;
	  if( j == C-1 ) rightt[i*C+j]=1;
	  else rightt[i*C+j]=rightt[i*C+j+1] + 1;
      }
    }

    int count_L = 0;
    for(int i = 0; i < R; i++)
    {
       for(int j = 0; j < C; j++)
       {
	count_L += count(topp[i*C+j], rightt[i*C+j])+count(topp[i*C+j], leftt[i*C+j]);
	count_L += count(bottomm[i*C+j], rightt[i*C+j]) + count(bottomm[i*C+j], leftt[i*C+j]);
       }
    }
    cout << "Case #"<<t<<": "<<count_L<<endl;
  }
  return 0;
}
