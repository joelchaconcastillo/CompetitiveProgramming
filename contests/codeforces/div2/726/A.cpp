#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t;
   cin >>t;
   while(t--)
   {
      long long sum = 0;
      int d, n;
      cin >>n;
      for(int i = 0; i < n;i++) cin >> d, sum+=d;
      if( sum-n >=0) cout << sum-n<<endl;
      else cout << 1<<endl;
   }
   return 0;
}
