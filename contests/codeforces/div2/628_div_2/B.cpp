#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  scanf("%d\n", &t);
  for(int i = 0; i < t; i++)
  {
    set<int> s;
    int n;
    scanf("%d\n", &n);
    for(int j = 0; j < n; j++)
    {
	int x;
	scanf("%d ", &x);
        s.insert(x);
    }
//    for(auto a = s.begin(); a != s.end(); a++)
//	{
//	printf("%d ", *a);
//	}
    printf("%d\n", (int)s.size());
	
  }
  return 0;
}
