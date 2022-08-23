#include <bits/stdc++.h>
using namespace std;
int main()
{
   int N;
   int cont = 0;
   while(scanf("%d", &N), N > 0)
   {
	if(cont++ > 0) printf("\n");
	int abcde, fghij;
	priority_queue< pair<int, int> > pq;
	for(int fghij = 1234; fghij <= 98765/N; fghij++)
        {
	  abcde = fghij*N;
 	 //Checking the turned on bits in each comparison..
	 int tmp, used = ( fghij < 10000);
	 //check abcde
 	  tmp = abcde;
	  while(tmp){ used |= (1<<(tmp%10)); tmp /=10; }
 	  tmp = fghij;
	  while(tmp){ used |= (1<<(tmp%10)); tmp /=10; }
	  if(  used == (1<<10)-1 )
	 	pq.push(make_pair( -abcde, -fghij ));

        }
	if(!pq.empty())
	{
	   while(!pq.empty()){ 
		  if(-pq.top().first < 10000)
		   printf("0%d / %d = %d\n", -pq.top().first, -pq.top().second, N); 
		  else if(-pq.top().second < 10000)
		   printf("%d / 0%d = %d\n", -pq.top().first, -pq.top().second, N); 
		  else
		   printf("%d / %d = %d\n", -pq.top().first, -pq.top().second, N); 
		  pq.pop();
		}
	}
	else printf("There are no solutions for %d.\n", N);
   }
}
