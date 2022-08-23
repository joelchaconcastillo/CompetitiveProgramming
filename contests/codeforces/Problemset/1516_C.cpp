#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, a[101], sum=0;
   cin>>n;
   for(int i = 0; i < n; i++)cin>> a[i], sum+=a[i];
   if(sum%2){ cout << "0\n"; return 0;}
   bitset<200005> b;
   b[0]=1;//first bit of zero-sum
   for(int i = 0; i <n; i++) b |= (b<<a[i]);
   if(b[sum/2]==0)
   {
      cout << "0\n";
      return 0;
   }
   pair<int, int> minp(30, -1);
   for(int i = 0; i < n; i++) minp = min(minp, make_pair(__builtin_ctz(a[i]),i+1));
   cout << "1\n"<<minp.second<<endl;
   return 0;
}
