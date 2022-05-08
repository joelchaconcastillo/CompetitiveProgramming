#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >>t;
  while(t--)
  {
     int n;
     cin>>n;
     vector<int> data(n);
     for(int i = 0; i < n; i++) cin >>data[i];
     sort(data.begin(), data.end());
     bool f=true;
     for(int i = 0; i < n-1; i++)
	     if(data[i+1]-data[i] > 1){ f=0;break;}
     if(f)cout<<"YES\n";
     else cout << "NO\n";
  }
  return 0;
}
