#include <bits/stdc++.h>
using namespace std;
string st;
list<string> l;
string decode(int i)
{
   auto it = l.begin();
   advance(it, i-1);
   string tw = *it;
   l.erase(it);
   l.push_front(tw);
   return tw;
}
int main()
{
  while(getline(cin, st))
  {
    if(st[0] == '0' && st.size() == 1) break;
    string w="", d="";
    for(auto c:st)
    {
       if(isalpha(c)) w +=c;
       else if(isdigit(c)) d +=c;
       if(!isalpha(c) && !w.empty())
       {
        cout << w;
        l.push_front(w);
	w  = "";
       }
       if( !isdigit(c) && !d.empty())
       {
            cout << decode(stoi(d)); d="";
       }
       if( !isalpha(c) && !isdigit(c))cout << c;
    }
    if( !w.empty())
    {
  cout << w;
        l.push_front(w);
	w  = "";
    }
    if( !d.empty())
    {
       cout << decode(stoi(d)); d="";
    }
    cout <<endl;
  }
  return 0;
}
