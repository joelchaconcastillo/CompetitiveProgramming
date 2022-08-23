#include <bits/stdc++.h>
using namespace std;
int main()
{
   int t, cont_one, cont_zero;
   cin >> t;
   while(t--)
   {
     string st;
     cin >> st;
     cont_one =cont_zero = 0;
     for(int i = 0; i < st.size(); i++)
	if(st[i] == '1') cont_one++;
	else if(st[i] == '0') cont_zero++;
     if( min(cont_one, cont_zero) % 2 == 1)
	cout << "DA\n";
     else cout << "NET\n";
   }
   return 0;
}
