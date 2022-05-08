#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while(t--)
  {
     int n;
     cin >>n;
     vector<int> d(n);
     for(int i = 0; i < n; i++)
	     cin >>d[i];
     sort(d.begin(), d.end());
//     if( n<=2)
//     {
//	cout << d[0]<< " " <<d[1]<<endl;
//	continue;
//     }
     pair<int, int> dif(INT_MAX, -1);
     for(int i = 0; i < n-1; i++)
	     if( dif.first > d[i+1]-d[i]) dif = make_pair(d[i+1]-d[i], i);
     cout << d[dif.second]<<" ";
     for(int i = dif.second+2; i < n; i++)
                cout << d[i]<<" ";
     for(int i = 0; i < dif.second; i++)
                cout << d[i]<<" ";
     cout << d[dif.second+1]<<endl;

  }
  return 0;
}
