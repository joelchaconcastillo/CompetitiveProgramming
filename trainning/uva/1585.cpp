#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  cin >> T;
  for(int i = 0; i<T; i++)
  {
     string st;
     cin >>st;
     int totalscore=0, prev=0;
     for(int a = 0; a < st.size(); a++)
     {
	if(st[a]=='X') prev=0;
	else if(st[a]=='O') prev++;
	totalscore += prev;	
     }
     cout << totalscore<<endl;
  }
  return 0;
}
