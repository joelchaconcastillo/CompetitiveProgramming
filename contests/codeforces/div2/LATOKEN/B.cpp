#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
  { 
   int n;
   cin >>n;
   vector<long long> d(n+2, 0);
   for(int i = 1; i <= n; i++) cin >>d[i];
   long long ini_score = d[1]+d[n]; 
   for(int i = 1; i < n; i++) ini_score += abs(d[i]-d[i+1]);
   for(int i = 1; i <=n; i++) 
   {
	if(d[i]>d[i-1] && d[i] > d[i+1])
	{
	   long long dif = d[i]-d[i-1];
	   dif = min(dif, d[i]-d[i+1]);
	   ini_score += (dif - 2*dif);
	}
   }
   cout << ini_score<<endl;
  }
  return 0;
}
