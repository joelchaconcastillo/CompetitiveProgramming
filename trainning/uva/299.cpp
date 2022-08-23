#include<bits/stdc++.h>
int data[51];
using namespace std;
int main()
{
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++)
  {
    int L, cont = 0;
    scanf("%d", &L);
    for(int j = 0; j < L; j++)
	scanf("%d ", &data[j]);
  
    for(int a = 0; a <L; a++)
    {
      for(int b = 0 ; b <L-1; b++)
      {
 	if(data[b] > data[b+1])
	{
	 cont++;
	 swap(data[b], data[b+1]);
	}
      }
    }
    printf("Optimal train swapping takes %d swaps.\n", cont);
  }
}

