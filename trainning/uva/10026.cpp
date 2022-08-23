#include <bits/stdc++.h>
using namespace std;
int main()
{
   int T;
   cin>>T;
   for(int t=0; t < T; t++)
   {
	if(t>0)cout <<endl;
	int n;
	pair<double, int> d[1001];
	cin >>n;
	for(int i = 0; i < n; i++)
	{
	   int t, s;
	   cin >> t>>s;
	  d[i].first=-s/(double)t, d[i].second=i;
	}
	sort(d, d+n);
	for(int i = 0; i < n; i++)
	{
	   cout << d[i].second+1;
	   if(i<n-1)cout << " ";
	}
	cout << endl;
   }
   return 0;
}
