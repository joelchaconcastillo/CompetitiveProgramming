#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin >> t;
   while(t--)
   {
      vector<int> l;
      int n, t;
      cin >>n;
     for(int i = 0; i < n; i++)
     {
	   cin >> t;
	   l.push_back(t);
     }
    sort(l.begin(), l.end());
    int i = (int)l.size()-1;
    for(; i >=0 && l[i] >  (i+1); i--);
    cout <<fixed<< i+2 <<endl;
    
   }
   return 0;
}
