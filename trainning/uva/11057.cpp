#include<bits/stdc++.h>
using namespace std;
 int data[10001]; //book cost

int bs(int value, int N)
{
   int low = 0, up=N-1;
   while(low <= up)
   {
      int middle = (low+up)/2;
      if( data[middle] > value )
          up=middle-1;
       else if (data[middle] < value)
	low = middle+1;
       else return middle;
   }
   return 0;
}
int main()
{
  int N; //number of books

 while(scanf("%d", &N) != EOF) //cin.getline() != EOF, cin >> N
 {
   for(int i = 0; i <N; i++)  scanf("%d ", &(data[i]));
   int current_cost;
   scanf("%d", &current_cost);
   //pre-sorting costs
   sort(data, data+N); //O(N log_2 N)
   int min_diff = INT_MAX;
   int idx=-1;
   for(int i = 0; i < N ; i++)
   {
      int complement = current_cost - data[i];
      if( complement < 0 ) continue;
      int j = bs(complement, N);
      if(i == j) continue;
      if(j)
      {
	if(min_diff > abs(data[i]-complement))
	{
	  min_diff = abs(data[i]-complement);
 	 idx = i;
	}
      }
   }
  printf("Peter should buy books whose prices are %d and %d.\n\n", data[idx], current_cost-data[idx]);
 }
  return 0;
}

