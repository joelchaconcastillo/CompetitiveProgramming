#include <bits/stdc++.h>
using namespace std;
int Z, I, M;
int f(int x){return (Z*x+I)%M; }
int floyd_cycle(int x0)
{
  int t = f(x0), h = f(f(x0));
  while( t!=h ) t=f(t), h = f(f(h));
  int mu = 0;
  h=x0;
  while(t != h )t=f(t), h=f(h), mu++; 
  int l = 1;
  h=f(t);
  while(t != h) h=f(h), l++;
  return l;
}
int main()
{
  int x, t=1;
  while(cin >> Z >> I >> M >> x)
  {
     if( Z == 0 && I == 0 && M == 0 && x == 0) break;
     cout<<"Case "<<t<<": " << floyd_cycle(x)<<endl;
   t++;
  }
  return 0;
}
