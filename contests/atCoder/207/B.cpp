#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long A, B, C, D;
  cin >>A>>B>>C>>D;
  long long k = 0;
  if( D*C<= B){ cout << -1<<endl;return 0;}
  while(A+B*k > D*(C*k))k++;
  cout << k<<endl;
  return 0;
}
