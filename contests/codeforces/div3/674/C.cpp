#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--)
  {
   long long n, minv = 1e9;
   cin>>n;
   for(long long i = 1; i*i<= n; i++)
	   minv = min(minv, i-1 + (n-1)/i);
   cout << minv<<endl;
  } 
  return 0;
}
