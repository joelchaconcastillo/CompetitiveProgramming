#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  vector<vector<int>> vi(3);
  cin >>n;
  for(int i = 0; i < n; i++)
  {
    int ti;
    cin >> ti;
    vi[ti-1].push_back(i);
  }
  int largest = min((int) vi[0].size(), min((int) vi[1].size(), (int) vi[2].size()));
  cout << largest<<endl;
  for(int i = 0; i < largest; i++)
  {
	for(int j = 0; j < 3; j++)
	   cout << vi[j][i]+1<< " ";
	cout << endl;
  }

  
  return 0;
}
