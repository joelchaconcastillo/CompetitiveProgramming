#include <bits/stdc++.h>
using namespace std;
int main()
{
  int k, n;
  cin >>k;
  while(k--)
  {
    int c1 = 0, c2 = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      int d;
	cin >>d;
      if(d==1)c1++;
	else if(d==2) c2++;
    }
    if( (c1%2)==0 && c1>0) cout << "YES"<<endl;
    else if( c1==0 && (c2%2)==0) cout << "YES"<<endl;
    else cout << "NO"<<endl;
  }
  return 0;
}
