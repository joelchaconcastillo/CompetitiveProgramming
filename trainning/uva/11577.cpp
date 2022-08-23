#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  cin.ignore();
  for(int i = 0; i < t; i++)
  {
     string st;
     getline(cin, st);
     int f[500];
     memset(f, 0, sizeof f);
     int maxf=0;
     string out="";
     for(auto s:st)
     {
	s=tolower(s);
      if(islower(s))
      {
	 f[s]++;
  	 if(f[s] > maxf)
	    maxf = f[s], out=s;
	 else if(f[s] == maxf)
	 out+=s;
      }
     }
     sort(out.begin(), out.end());
     cout << out << endl;
  }
  return 0;
}
