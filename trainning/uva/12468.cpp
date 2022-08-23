#include <bits/stdc++.h>
using namespace std;
int main()
{
  int start, end;
  while(cin >>  start >> end, (start != -1 && end != -1) )
  {
     int a = min(start, end), b = max(start, end);
     if( b-a < (a+100-b) ) cout << b-a <<endl; else cout << a+100-b<<endl;
  }
}
