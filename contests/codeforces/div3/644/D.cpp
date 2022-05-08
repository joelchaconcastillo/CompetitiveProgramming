#include <bits/stdc++.h>
#define MAX_N 1e5
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int t;
   cin >> t;
   while(t--)
   {
      long long n, k;
      cin>>n>>k;
      if(n<=k){cout <<1<<endl;continue;}
      if(k==1){cout <<n<<endl;continue;}
      long long mind=n;
      for(long long i = 1; i*i <=n; i++)
      {
	      if(n%i==0)
	      {
		 if(i<=k) mind=min(mind, n/i);
		 if(n/i<=k) mind=min(mind, i);
	      }
      }
      cout << mind<<endl;

   }
   return 0;
}

