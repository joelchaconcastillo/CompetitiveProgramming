#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  scanf("%d\n", &t); 
  long data[100001], data2[100001];
  for(int i = 0; i < t; i++)
  {
     int n;
     scanf("%d\n", &n);
     for(int j = 0; j < n; j++)
	scanf("%ld ", &data[j]);
     sort(data, data+n);
     int s=0, e=n-1, k=0;
     while(s <= e) 
     {
	data2[k++] = data[s];
	if(s < e)
	data2[k++] = data[e];
	s++, e--;
     }
     for(int k = n-1; k >=0; k--) printf("%ld ", data2[k]);
     printf("\n");
  }
  return 0;
}

