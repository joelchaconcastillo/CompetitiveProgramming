#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


int main()
{
  int n,m;
  while(scanf("%d %d", &n, &m), n && m )
  { 
     unordered_set<int> Jack;
     for(int i = 0; i < n; i++)
     {
        int d;
        scanf("%d", &d);
        Jack.insert(d);
     }
     int match = 0;
     for(int i = 0; i < m; i++)
     {
        int d;
        scanf("%d", &d);
	if( Jack.find(d) != Jack.end())
	match++;
     }
     printf("%d\n", match);
  }
  return 0;
}
