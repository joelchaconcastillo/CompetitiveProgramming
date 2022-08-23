#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
     int n;
     cin>>n;
     string s;
     cin>>s;
     s+=" ";
     map<int, bool> check;
     bool f=0;
     for(int i = 0; i < n; i++)
     {
	 if( s[i] != s[i+1])
	 {
            if(check[s[i]])
	    {
	       f=1; 
	       break;
	    }
	    check[s[i]]=1;
	 }
     }
     if(!f)cout << "YES\n";
     else cout <<"NO\n";
  }
  return 0;
}
