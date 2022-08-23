#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N, Q;
  string s;
  scanf("%d %d", &N, &Q);
  for(int i = 0; i < N; i++) s += i+'A';
  for(int i = 0; i < N; i++)
  {
    for(int j = 0; j < N-1; j++)
    {
      printf("? %c %c\n", s[j], s[j+1]);
      fflush(stdout);
      char a;
      scanf("%c", &a);
      printf("%c ", a);
      return 0;
      if(a=='>') swap(s[j], s[j+1]);
    }
  }
    printf("! %s\n", s.c_str());
    fflush(stdout);
  return 0;
}
