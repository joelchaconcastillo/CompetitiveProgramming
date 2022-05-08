#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  int d[5001], accum[5001];
  cin >> t;
  while(t--)
  {
    int n, s = 0;
    bool flag = false;
    cin >> n;
    memset(accum, 0, sizeof d);
    int maxsum = -100000;
    while(n--)
    {
	 int num;
	 cin >>num;
	 d[s++] = num;
         accum[num]++;
	 maxsum= max(maxsum, accum[num]);
    }
    if(maxsum > 2) cout <<"YES"<<endl;
    else
    {
    for(int i = 0; i < s && !flag; i++)
    {
      for(int j = i+2; j  < s && !flag; j++)
      {
	if(d[i] == d[j])flag=true;
      }
    }
    if(flag) cout << "YES"<<endl;
    else cout << "NO" <<endl;
    }
  }
  return 0;
}
