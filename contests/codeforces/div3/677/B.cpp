#include <bits/stdc++.h>
using namespace std;
int main()
{
  int ite, n, d[100];
  cin>>ite;
 while(ite--)
 {
   cin>>n;
   int nz=0;

   for(int i = 0; i < n; i++)
       cin >> d[i], nz +=(d[i]==0);
   int idx = 0, outz=0;
   while(d[idx]==0)idx++, outz++;
   idx = n-1;
   while(d[idx]==0)idx--, outz++;
   cout << nz - outz<<endl;

 } 
  return 0;
}
