#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >>t;
  while(t--)
  {
    int n;
    cin >>n;
    vector<long long> a(n);
    set<pair<long long, int> > sa;
    long long c=0;
    for(int i = 0; i < n; i++)cin >> a[i], sa.insert(make_pair(a[i], i+1));
    for(int i = 0; i < n ; i++)
    {
	sa.erase( make_pair(a[i], i+1));
	auto first = sa.lower_bound(make_pair( (2*i+1LL)/a[i], n));
	auto last = sa.upper_bound(make_pair( (n+i+1+a[i])/a[i], n));
	for(auto j = first ; j!=sa.end() && j!=last ; j++)
		if(a[i]*j->first == i+1+j->second) c++;
    }
    cout << c<<endl;
  }
  return 0;
}
