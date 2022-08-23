#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 3001
int main()
{
  int n;
  int diffa[MAX_SIZE];
  while(scanf("%d", &n) != EOF)
  {
   memset(diffa, 0, sizeof(int)*n);
   int prev;
   scanf("%d\n", &prev);
   for(int i = 0; i < n-1; i++)
   {
      int current;
      scanf("%d ", &current);
      diffa[abs(current - prev)]++;
      prev=current;
   }
   bool pass = true;
   for(int i = 1; i <= n-1; i++) if(diffa[i] == 0) pass=false;
   if(pass) printf("Jolly\n");
   else  printf("Not jolly\n");
 
  }
  return 0;
}
