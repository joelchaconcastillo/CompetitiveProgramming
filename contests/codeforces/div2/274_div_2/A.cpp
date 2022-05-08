#include <bits/stdc++.h>
using namespace std;
int main()
{
  set<int> s;
  int a,b,c;
  cin>>a>>b>>c;
  s.insert(-(a+(b*c)));
  s.insert(-((a+b)*c));
  s.insert(-((a*b)+c));
  s.insert(-(a*(b+c)));
  s.insert(-(a+b+c));
  s.insert(-(a*b*c));
  cout << -(*(s.begin()))<<endl;
  return 0;
}
