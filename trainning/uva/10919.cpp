#include <bits/stdc++.h>
using namespace std;
int main()
{
   int k, m;
   while((cin >> k >> m), k)
   {
      set<string> selected;
      for(int i = 0; i < k; i++)
      {
	string tmp;
	cin >>tmp;
	selected.insert(tmp);
      } 
      int r, c, cont=0;
      bool flag = true;
      for(int i = 0; i  < m; i++)
      {
	  cont = 0;
          cin >> r >>c;
          for(int j = 0; j  < r; j++)
          {
            string tmp;
            cin >> tmp;
            if( selected.find(tmp) != selected.end()) cont++;
          } 
	  if( cont < c) flag=false;
      }
	if(flag) cout << "yes"<<endl;
	else cout << "no"<<endl;
   }
}
