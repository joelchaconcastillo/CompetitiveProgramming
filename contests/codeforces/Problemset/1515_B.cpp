#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>> t;
  while(t--)
  {
     int n;
     cin>>n;
     int x1 = sqrt(n/2), x2=sqrt(n/4);
     if(n== 2*x1*x1 || n==4*x2*x2 ) cout<<"YES\n";
     else cout << "NO\n";
  }
  return 0;
}
