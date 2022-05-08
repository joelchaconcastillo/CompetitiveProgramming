#include <bits/stdc++.h>
using namespace std;
int main()
{
   string st;
   while(cin >> st)
   { 
      if(st[0] == '0' && st.size() ==1) break;
      long long n = 0;
      for(int i = 0; i < st.size(); i++) n += (st[st.size()-i-1]-'0')*((1<<(i+1))-1);
      cout << n<<endl;
   }
}
