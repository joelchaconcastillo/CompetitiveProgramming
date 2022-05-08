#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  int num[12], den[12];
  num[2] = 1, den[2]=2;
  num[3] = 2, den[3]=6;
  for(int i = 4; i <= 12; i++) num[i] = (i-1)*(num[i-2]+num[i-1]), den[i] = (i-1)*(den[i-2]+den[i-1]);
  while(T--)
  {
    int n;
    cin >> n;
    cout <<num[n]<<"/"<<den[n]<<endl; 
  }
  return 0;
}
