#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int n, x, y;
      cin>>n>>x>>y;
      if(n==2){cout << x<<" "<<y<<endl;continue;}
      int r = y-x, d=1;
      for(; d <= r; d++)
	  if(r%d==0 && r/d+1 <= n)break;
	  int z = min((y-1)/d, n-1);
	  int s = y-d*z;
	  for(int i = 0; i < n; i++)
		  cout << i*d+s<<" ";
	cout <<endl;
  }
  return 0;
}
