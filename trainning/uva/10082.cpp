#include <bits/stdc++.h>
using namespace std;
int main()
{
  string st = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
  char h[500]; 
  for(int i = 0; i < st.size(); i++) h[st[i]]=i;
  string str;
  while(getline(cin, str))
  {
     for(auto c:str)
     {
	if( c==' ') cout<<c;
	else cout << st[h[c]-1];
     }
	cout <<endl;
  }
  return 0;
}
