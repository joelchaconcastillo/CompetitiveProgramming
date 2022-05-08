#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  char c;
  int count[300];
  count['D'] = 0;
  count['A'] = 0;
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
  {
   scanf("%c", &c);
   count[c]++;
  }
  if(count['D'] > count['A']) printf("Danik\n");
  else if(count['D'] < count['A']) printf("Anton\n");
  else printf("Friendship\n");

  return 0;
}
