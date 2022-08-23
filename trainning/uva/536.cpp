#include <bits/stdc++.h>
using namespace std;
string pre, in;
vector<int> idxpre, idxin;
void fastrebuild(int L, int R, int idp)
{
  if(L>=R || L<0 || R>in.size())return;
  int pos = idxin[pre[idp]];
  fastrebuild(L, pos, idp+1);
  fastrebuild(pos+1, R, idp+pos-L+1);
  cout << in[pos];
}
int main()
{
  idxpre.assign(500, 0);
  idxin.assign(500, 0);
  while(cin>>pre>>in)
  {
    for(int i = 0; i < pre.size(); i++)
     idxpre[pre[i]]=i, idxin[in[i]]=i;
    fastrebuild(0, in.size(), 0);
	cout <<endl;
  }
  return 0;
}
