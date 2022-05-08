#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   string s;
   while(getline(cin, s))
   {
      if(s[0]=='.')break;
      int n = s.size(), k=1;
      bool f=1;
      while(k<=n)
      {
	  if((n%k)==0)
	  {
	      f=1;
	 for(int i = k; i+k <= n; i+=k)
	 {
            if(s.substr(0, k) != s.substr(i, k)){f=0; break;}
	 }
	 if(f)break;
	  }
	  k++;
      }
      cout <<n/k<<endl;
   }
   return 0;
}
