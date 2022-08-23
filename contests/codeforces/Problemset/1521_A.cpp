#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     long long A,B, x, y, z;
     cin>>A>>B;
     x = A, y=A*B, z= A*(1+B);
     if( B==1) cout << "NO\n";
     else cout <<"YES\n" <<x << " " << y<<" "<<z<<endl;
  }
  return 0;
}
