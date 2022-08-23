#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  long long sum;
  cin>>t; 
  while(t--)
  {
    vector<pair<int, int>>d;
    int n;
    long long sum=0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
	    int tt;
	cin>>tt;
	d.push_back({tt, i+1});
	sum+=tt;
    }
    sort(d.begin(), d.end());
    int idx = 0;
    for(int i = n-2; i >=0; i--)
    {
      sum -= d[i+1].first;
      if( sum < d[i+1].first)
      { 
         idx=i+1;
	 break;
      }
    }
    vector<int> out;
    for(int i = idx; i < n; i++)
      out.push_back(d[i].second);
    sort(out.begin(), out.end());
    cout << out.size()<<endl;
    for(auto i:out)cout << i <<" ";
    cout <<endl;
  }
  return 0;
}
