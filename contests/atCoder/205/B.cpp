#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N,a;
  cin >> N;
  vector<int> d(N+1,0);
  for(int i = 0; i < N ; i++) cin >> a, d[a]=1;
  for(int i = 1; i <= N; i++)
	  if(d[i] == 0) {cout << "No"<<endl; return 0;}
  cout << "Yes\n";
  return 0;
}
