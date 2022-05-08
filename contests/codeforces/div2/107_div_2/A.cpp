#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,k,l,c,d,p,nl,np;  
  cin >> n >>k >> l>> c >> d >>p >> nl >> np;
  cout << floor( min( (int)floor(k*l/nl), min(c*d, (int)floor(p/np))) /n)<<endl;

  return 0;
}
