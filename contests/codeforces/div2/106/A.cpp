#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n, k1, k2, w, b;
    cin>>n>>k1>>k2;
    cin>>w>>b;
    int nw = (k1+k2)/2;
    int nb = (2*n-k1-k2)/2;
    if(nb>=b && nw>=w)
    cout <<"YES" <<endl;
    else cout <<"NO"<<endl;

  }
  return 0;
}
