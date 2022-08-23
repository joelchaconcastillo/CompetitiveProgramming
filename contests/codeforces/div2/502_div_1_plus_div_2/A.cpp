#include <bits/stdc++.h>

using namespace std;
int main()
{
  int n;
  cin >> n;
  priority_queue<pair<double, int>> pq;
  for(int i = 0; i < n; i++)
  {
	int a1,a2,a3,a4;
	cin >> a1 >> a2 >> a3 >> a4;
	pq.push(make_pair(a1+a2+a3+a4, -i));
  }
  int rank = 1;
  while(pq.top().second != 0){ pq.pop(); rank++;}
  cout << rank <<endl; 
  return 0;
}
