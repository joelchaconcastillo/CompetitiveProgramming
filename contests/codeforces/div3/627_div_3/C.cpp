#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
   string s;
   cin>>s;
   s ="R"+s+"R";
   int maxv = -1, li = 0, n = s.size();
   
   for(int i = 0; i < n; i++)
   {
	if(s[i] == 'R')
	{
	 if(i-li>maxv)maxv = i-li;
	 li = i;
	}
   }
   cout << maxv <<endl;
  }
}
