#include <bits/stdc++.h>

using namespace std;
int main()
{
  int n, a=0, b=0;
  cin >>n;
  for(int i = 0; i < n; i++)
  {
   int xi;
   cin >>xi;
   if(xi%2 == 0)  a++; else b++;
  }
  cout << min(a,b)<<endl;
  return 0;
}
