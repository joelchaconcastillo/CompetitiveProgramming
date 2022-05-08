#include <bits/stdc++.h>
using namespace std;
int main()
{
  int tt;
  cin>>tt;
  for(int t=1; t<=tt; t++)
  {
    int n;
    string st;
    cin>>n>>st;
    vector<long long>d(n,1);
    for(int i=1;i<n; i++)
    {
 	if( st[i] > st[i-1]) d[i] += d[i-1];
    }
    cout << "Case #"<<t<<": ";
    for(int i = 0; i < n-1; i++) cout << d[i]<< " ";
    cout <<d[n-1]<<endl;
  }
  return 0;
}
