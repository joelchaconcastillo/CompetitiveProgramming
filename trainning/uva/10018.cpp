#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string &st)
{
  for(int s=0, e=st.size()-1; s<e;s++, e--)
     if(st[s] != st[e]) return false;
  return true;
}
int main()
{
  int k;
  cin >> k;
  while(k--)
  {
    string st;
    cin >> st;
    int ite=0;
    
    do{
	 st= to_string(stol(st) + stol(string(st.rbegin(), st.rend())));
	ite++;
    }while(!ispalindrome(st));
    cout << ite<< " "<<st<<endl; 
  }
  return 0;
}
