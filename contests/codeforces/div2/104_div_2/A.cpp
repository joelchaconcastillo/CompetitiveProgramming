#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T, n, d[100];
  cin >> T;
  while(T--)
  {
    cin >>n;
   for(int i = 0; i < n; i++)cin >> d[i]; 
   sort(d, d+n);
   int c=0;
   for(int i = 1; i < n; i++) if(d[i]>d[0])c++;
   cout << c<<endl;
  }
  return 0;
}
