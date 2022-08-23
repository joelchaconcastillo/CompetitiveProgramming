#include <bits/stdc++.h>
using namespace std;
int main()
{
  string st;
  getline(cin, st);
  map<char, bool> mm;
  int cont = 0;
  for(int i = 1; i < (int)st.size()-1; i++)
  {
	if( st[i] == '{' || st[i] == '}' || st[i] == ',' || st[i] == ' ') continue;
  	if(mm[st[i]]) continue;	
	else
	{
	   mm[st[i]] = true;
	   cont++;
	}
   }  
   cout << cont <<endl;
  return 0;
}
