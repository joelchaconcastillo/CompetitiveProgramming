#include <bits/stdc++.h>
using namespace std;
int main()
{
   char in[1000001];
   while(scanf("%s", in), strcmp(in, "END") != 0)
   {
      int i = 1, x1 = strlen(in), x2;
      sscanf(in, "%d", &x2);
      while(x1 != x2)
      {
	int n=0;
        for(int j = x1; j > 0; j/=10, n++);
	x2 = x1;
	x1 =n;
        i++;
      }
      printf("%d\n", i);
   }
   return 0;
}
