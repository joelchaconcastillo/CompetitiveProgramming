#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n, a[100000], b[100000];
     bool d[4001];
     cin>>n;
     for(int i = 0; i < n; i++)cin>>a[i];
     for(int i = 0; i < n; i++)cin>>b[i], d[a[i]-b[i]+1000]=1;
     int l=0, r=n-1;
     while(l<n &&a[l] == b[l])l++;
     while(r>=0 && a[r] == b[r])r--;
     if(l > r) cout <<"YES\n"; //equals
     else
     {
         int di=a[l]-b[l];
	 bool f = 1;
	 for(int i = l; i <= r && f; i++) if( a[i]-b[i] != di)f=0;
	 if(f  && di < 0) cout << "YES\n";
	 else cout << "NO\n";
     }
  }
  return 0;
}
