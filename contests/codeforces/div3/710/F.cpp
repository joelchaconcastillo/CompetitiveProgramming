#include <bits/stdc++.h>
using namespace std;
int path(pair<int, int> from, pair<int, int> to)
{
   if(from.first-from.second ==  to.first-to.second)
	   return ((from.first+from.second)%2==1)?0:to.first-from.first;
   to.first = to.first-from.first+1;
   to.second = to.second-from.second+1;
   return ((from.first+from.second )%2 == 0)? ((to.first-to.second)/2):((to.first-to.second+1)/2);
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     	int n;
	cin>>n;
	vector<pair<int, int> >d(n);
	for(int i = 0; i < n; i++)
          cin>>d[i].first;
	for(int i = 0; i < n; i++)
          cin>>d[i].second;
        sort(d.begin(), d.end());
	long long sum = 0;
	pair<int, int> c (1,1);
        for(int i = 0; i < n; i++)
	{
		sum+= path(c, d[i]);
	       	c=d[i];
	}
	cout <<sum<<endl;
  }
  return 0;
}
