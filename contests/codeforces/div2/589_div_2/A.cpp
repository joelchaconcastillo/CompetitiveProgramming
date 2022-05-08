#include <bits/stdc++.h>
using namespace std;
int main()
{
  int l, r;
  cin >> l >>r;
  int count[10];
  int found = -1;
  for(int i = l; i <=r; i++)
  {
    memset(count, 0, sizeof count);
    string st = to_string(i);
    bool f = true;
    for(auto a = st.begin(); a != st.end(); a++)
    {
	if(count[(*a)-'0'] >  0 ) f=false;
	count[(*a)-'0']++;
    }
    if(f) {found=i; break;};
  }
  if(found != -1) cout << found <<endl;
  else cout <<"-1\n";
  return 0;
}
