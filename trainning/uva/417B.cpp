#include <bits/stdc++.h>
using namespace std;
int cont=1;
map<string, int> d;
void bk(string st, int l)
{
  if(st.size() == l)
  {
     d[st]=cont++;
     return;
  }
  char c;
  if(st.empty())c='a';
  else c= st.back()+1;
  for(char k = c; k <= 'z'; k++)
     bk(st+(char)k, l);
}
int main()
{
  for(int i = 1; i <=5;i++) bk("", i); 
  string st;
  while(getline(cin ,st))
  {
      cout << d[st]<<endl;
  }
  return 0;
}
