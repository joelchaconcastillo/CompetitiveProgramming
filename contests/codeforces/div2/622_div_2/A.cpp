#include <bits/stdc++.h>

using namespace std;
int cf(int a, int b, int c)
{
  int cont = 0;
  if( a > 0) cont++, a--;
  if( b > 0) cont++, b--;
  if( c > 0) cont++, c--;
  if(a > 0 && b > 0) cont++, a--, b--;
  if(a > 0 && c > 0) cont++, a--, c--;
  if(b > 0 && c > 0) cont++, b--, c--;
  if(a > 0 && b > 0 && c > 0) cont++,a--, b--, c--;
  return cont;
}
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int a,b,c, cont=0;
    cin >> a >> b >> c;
    cont = max(cont, cf(a,b,c));
    cont = max(cont, cf(a,c,b));
    cont = max(cont, cf(b,a,c));
    cont = max(cont, cf(b,c,a));
    cont = max(cont, cf(c,a,b));
    cont = max(cont, cf(c,b,a));
    cout << cont <<endl;
    
  }
  return 0;
}
