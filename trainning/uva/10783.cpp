#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++)
  {
    int a,b, sum=0;
    cin >> a >>b;
    for(int t = a; t<=b; t++) if(t%2) sum+=t;
    cout << "Case "<<i<<": "<<sum<<endl;
  }
}
