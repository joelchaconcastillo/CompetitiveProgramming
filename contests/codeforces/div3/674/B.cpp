#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
//  cin.tie(false);
  int t;
  cin>>t;
  while(t--)
  {
     int n,m;
     cin>>n>>m;
    bool f=0;
     for(int i = 0; i < n; i++)
     {
       int tl, tr, bl, br; 
       cin>>tl>>tr>>bl>>br;
       if(tr == bl) f=1;
     }
     if( (m%2) != 0 )f=0;
     if(f)cout <<"YES\n";
     else cout << "NO\n";
  }
  return 0;
}
