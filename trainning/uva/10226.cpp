#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T, total=0;
  string str;
  map<string, int> ss;
  cin >>T;
  getline(cin, str);
  getline(cin, str);
  while(T--)
  {
    getline(cin, str);
    while(!str.empty())
    {
       ss[str]++;
       total++;
       getline(cin, str);
    }
	for(auto i = ss.begin(); i != ss.end(); i++)
	    cout << i->first << " " << fixed<< setprecision(4) << (100.0*i->second)/(double)total <<endl;
        if( T > 0 )
	cout <<endl;
 	total = 0;
	ss.clear();
  }
  return 0;
}
