#include <bits/stdc++.h>
using namespace std;
int main()
{
   long long n, M;
   cin >>n >>M; 
   vector<vector<int> > f(60, vector<int> (2010)), s(60, vector<int> (2010));
   vector<int> ans(55,0);
   f[0][0]=1; //case base
   int nlowtri = n*(n-1)/2;
   for(int i = 0; i <= nlowtri; i++) s[0][i]=1;
   //precalculation
   for(int i = 1; i <=n ; i++)
   {
     for(int j = 0; j <= nlowtri; j++) // lower triangular matrix..
     {
        if(j>=i) f[i][j] = (s[i-1][j]-s[i-1][j-i]+M)%M;
	else f[i][j] = s[i-1][j];
        if(j>0)s[i][j] = (s[i][j-1] + f[i][j])%M;
        else s[i][j] = f[i][j]%M;
     }
   }
   for(int i = 1; i <=n; i++)
   {
     for(int j = 1; j<=i; j++)
     {
       for(int k = j+1; k<=i; k++)
       {
	for(int o = 0; o <= ((i-1)*(i-2))/2; o++)
	{
	   int t = o-(k-j)-1;
           if(t<0) continue;
	  ans[i]= (ans[i]+1LL*f[i-1][o]*s[i-1][t]%M)%M;
	}
       }
     }
   }

   for(int i = 2; i <=n; i++) ans[i] = (ans[i]+1LL*i*ans[i-1])%M;
   cout << ans[n]<<endl;
   return 0;
}
