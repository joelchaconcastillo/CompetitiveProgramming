#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
//  int output[1001]={0};
  while(scanf("%d", &n), n)
  {
   while(true)
   {
      stack <int> st;
      int match = 0;
      int num;
      scanf("%d", &num);
      if(!num) break;

      for(int i = 1; i <= n; i++)
      {
       st.push(i);
       while(!st.empty()  && num==st.top())
       {
          st.pop();
          match++;
	  if(match < n)
          scanf("%d", &num);
       }
      }  
      if(match == n) printf("Yes\n");
      else printf("No\n");
      for(;match<n-1; match++)
          scanf("%d", &num);
    }
    printf("\n");
  }
  return 0;
}
