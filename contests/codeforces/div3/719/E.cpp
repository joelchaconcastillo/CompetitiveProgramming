#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    string s;
    cin>>n;
    cin>>s;
    vector<int> idx;
    for(int i = 0; i < s.size(); i++)
	    if(s[i]=='*')idx.push_back(i);
    vector<pair<int, int>> d;
    int N =idx.size();
    for(int i = 0; i < N-1; i++)
	    d.push_back(make_pair(idx[i+1]-idx[i]-1, min(i+1, N-i-1)));
    sort(d.begin(), d.end());
    long long sum = 0;
    for(int i = 0; i < d.size(); i++)
    sum += (d[i].first)*(d[i].second);
    cout << sum<<endl;
  }
  return 0;
}
