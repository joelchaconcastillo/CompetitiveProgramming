#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  unordered_map<char, int> count;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    string st;
    cin >> st;
    count[(int)st[0]]++;
  }
  int total = 0;
  for(auto i = count.begin(); i != count.end(); i++)
  {
    if( i->second <=1) continue;
    int a1 = i->second / 2, a2 = i->second - a1;
    total += a1*(a1-1)/2 + a2*(a2-1)/2; 
  }
  cout << total<<endl;
  return 0;
}
