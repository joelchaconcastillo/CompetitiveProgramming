#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >>n;
    vector<int> d(n);
    for(int i = 0; i < n; i++) cin>>d[i];
    sort(d.begin(), d.end());
    int minv=INT_MAX;
    for(int i = 0; i < n-1; i++) minv=min(minv, d[i+1]-d[i]);
    cout << minv<<endl;
  }
  return 0;
}
