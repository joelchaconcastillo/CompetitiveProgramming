#include<bits/stdc++.h>
using namespace std;
int main()
{
  int d[4];
  cin >> d[0]>>d[1]>>d[2]>>d[3];
  string st;
  cin >>st;
  long long sum = 0;
  for(int i = 0; i < st.size(); i++) sum += d[st[i]-'0'-1];
  cout << sum<<endl;

  return 0;
}
