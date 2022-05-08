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
     for(int i = 0; i<n; i++)cin>>d[i];
     sort(d.begin(), d.end());
     vector<int>parity(2,0);
     int c=0;
    for(int i = 0; i < n; i++)
     {
         if(i+1< n && d[i+1]-d[i] == 1)
	 {
		 parity[d[i]%2]++;
		 parity[d[i+1]%2]++;
		 c++;
		 i++;
		 continue;
	 }
         parity[d[i]%2]++;
     }
     if(parity[0]%2==0 && parity[1]%2==0)cout <<"YES\n";
     else if(parity[0]%2==1 && parity[1]%2==1 && c>0) cout << "YES\n";
     else cout << "NO\n";
  }
  return 0;
}
