#include <bits/stdc++.h>
using namespace std;
int main()
{
   string st;
   while(getline(cin, st))
   {
      int cont = 0;
      for(int i = 0; i < st.size()-1; i++) if( isalpha(st[i]) && !isalpha(st[i+1])) cont++;
      if(isalpha(st[st.size()-1]))cont++;
      cout << cont <<endl;
   }
   return 0;
}
