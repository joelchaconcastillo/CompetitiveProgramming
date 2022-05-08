#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n, E=0;
     cin>>n;
     vector<int> d(n);
     for(int i = 0;i<n; i++)
        cin>>d[i], E+=d[i];
     if( E%n != 0){cout << -1<<endl; continue;}
     E/=n;
     int t=0;
     for(int i = 0;i<n; i++) if(d[i]>E)t++;
     cout << t<<endl;
  }
  return 0;
} 
