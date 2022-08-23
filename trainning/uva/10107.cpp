#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long int X;
  int i=0;
  long long data[10001];
  while(cin >> X)
 {
   data[i++] = X;
  sort(data, data+i);
  int m = i/2;
  if( (i % 2) == 0) cout << (long long)(data[m-1]+data[m])/2<<endl;
  else cout << data[m]<<endl;
  }
  return 0;
}
