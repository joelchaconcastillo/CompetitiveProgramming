#include <bits/stdc++.h>
using namespace std;
int main()
{
  string st;
  cin >> st;  
  int cont = 0;
  for(auto i  = st.begin(); i != st.end(); i++)
     if( *i == 'a') cont++;
  if(cont > st.size()-cont) cout << st.size()<<endl;
  else cout << (cont*2)-1<<endl;
  return 0;
}
