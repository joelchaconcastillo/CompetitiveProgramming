#include <bits/stdc++.h>
using namespace std;
int main()
{
 int b;
 scanf("%d\n", &b); 
 for(int r = 0; r < b; r++)
 {
    int s;
    scanf("%d\n", &s);
    int maxsum = 0, bi=1, bj=2, ci=1, currentsum=0;
    for(int i = 2; i <= s; i++)
    {
      int nice;
      scanf("%d\n", &nice);
      currentsum += nice;
      if(currentsum < 0)
      {
	currentsum = 0;
	ci = i;
	continue;
      }
      else if(maxsum == currentsum )
      {
	 if( i-ci > bj-bi  )
	 {
	   bi = ci;
	   bj = i;
	 }
      }else if(maxsum < currentsum)
      {
	maxsum = currentsum;
	bi = ci;
	bj = i;
      }
    }
    if( maxsum > 0)
     printf("The nicest part of route %d is between stops %d and %d\n", r+1, bi,bj);
    else
     printf("Route %d has no nice parts\n", r+1);

 }
}
