#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n, x;
    cin>>n>>x;
    n-=2;
    if( n <=0) cout <<"1\n";
    else cout << ceil(n/(double)x)+1<<endl;
  }
  return 0;
}
