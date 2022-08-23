#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;
int main()
{
  int n=101, a,b, c=1;
  
  while(cin>>a>>b, a!=0 && b!=0)
  {

    vector<vector<int> > mtx(n, vector<int> (n, MAXN));
    vector<bool>exist(MAXN, 0);
     int cont = 0;
     mtx[a][b]=1, exist[a]=1, exist[b]=1;
     while(cin>>a>>b, a!=0 && b !=0) mtx[a][b]=1, exist[a]=1, exist[b]=1;
     int sum=0;
     for(int k=0; k < n; k++)
     {
	if(!exist[k])continue;
       for(int i = 0; i< n; i++)
       {
	if(!exist[i])continue;
         for(int j = 0; j < n; j++) 
	 {
	if(!exist[j])continue;
	   if(i==j)continue;
	   mtx[i][j]=min(mtx[i][j], mtx[i][k]+mtx[k][j]);
	 }
       }
     }
     for(int i = 0; i < n; i++)
	{	
	  if(!exist[i]) continue;
          for(int j = 0; j < n; j++)	
	  {
	      
	  if(!exist[j]) continue;
	  if(mtx[i][j]!=MAXN)
		sum+=mtx[i][j], cont++;
	  }
	}
double d=sum/(double)cont;
	cout <<"Case "<<c++<<": average length between pages = "<<fixed<<setprecision(3)<<d <<" clicks"<<endl; 
  }
  return 0;
}
