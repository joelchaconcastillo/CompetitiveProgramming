#include <bits/stdc++.h>
using namespace std;
int gx[]={-1, 0, 1, 0},gy[]={0, -1, 0, 1};
int main()
{


  int n, d[200*200], t;
  cin>>t;
  while(t--)
  {
  cin>> n;
  int cont = 0;
  for(int i = 0; i<n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      d[i*n+j]=(cont+1);
     cont +=2;
     if( (cont+1)> n*n)cont=1;
    }
  }
  bool f=0;
  //check;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      for(int k = 0; k < 4; k++)
      {
	 int ii = (i+gx[k]), jj = (j+gy[k]);
        if(ii >=0 && ii < n &&  jj >=0 && jj < n )
	{
	
	    if(fabs(d[ii*n+jj] - d[i*n+j]) <=1) f=1;
	}
	if(f)break;
      }
	if(f)break;
    }
	if(f)break;
  }
  if(f) cout << "-1\n";
  else
  {
    for(int i = 0; i < n ; i++)
    {
       for(int j = 0; j <n; j++)
       {
	 cout << d[i*n+j]<<" ";
       }
       cout <<endl;
    }
  }

  }
  return 0;
}
