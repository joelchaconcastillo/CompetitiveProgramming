#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  while(cin>>n)
  {
    if(n==0) break; 
    long long p1=0, p2=1;
    for(long long i = 0, tmp; i < n; i++, tmp = p1, p1=p2, p2 = tmp+p2);
    cout << p2 << endl;
    
  }
  return 0;
}
