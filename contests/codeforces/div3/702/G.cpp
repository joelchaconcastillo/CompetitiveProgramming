#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n, m, a[200000], x[200000];
     vector<long long > prefix;
     vector<int> index;
     cin>>n >> m;
     long long sum=0;
     for(int i = 0 ; i < n; i++)
     {
	 cin >> a[i];
	 sum += a[i];
	 if(prefix.empty() || prefix.back() < sum)
	 prefix.push_back(sum), index.push_back(i);
     }
     for(int i = 0 ; i < m; i++) cin >> x[i];
     for(int i = 0; i < m; i++)
     {
       if( prefix.back() < x[i] && sum <=0)
       {
	cout<<"-1 ";
	continue;
       }
       long long cycle = 0;
       if( prefix.back() < x[i])
         cycle = ceil(( x[i]-prefix.back())/(double)sum);
         x[i] = x[i] - cycle*sum;
	 int idx = lower_bound(prefix.begin(), prefix.end(), x[i])-prefix.begin();
       cout << n*cycle + index[idx]<<" ";
     } 
     cout<<endl;
  }
  return 0;
}
