#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t, n;
  int data[100];
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
  {
     scanf("%d\n", &t);
     int mod ;	
     bool f=true;
     for(int j = 0; j < t; j++)
     {
	int a;
 	scanf("%d ", &a);
	if(j==0) mod = a%2;
	else
	 if( (a%2) != mod) f=false;
     }	
     
      if(f) printf("YES\n");
	else printf("NO\n");
  }
  return 0;
}
