#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, l;
   double w;
   while(scanf("%d %d %lf\n", &n, &l, &w)!= EOF)
   {
	int cont = 0;
	w /=2.0;
	priority_queue< pair< double, double> > pq;
	for(int i = 0; i < n; i++)
	{
		int c, r;
		scanf("%d %d\n", &c, &r);
		if((double)r <= w ) continue;
		double half =  sqrt((double)r*r  - ( (w*w)  ));
		double start = c-half;
		double end = c+half;
		pq.push(make_pair(  -start,  end));
	}
	if(pq.empty())
	{
           printf("-1\n");
	   continue;
	}
	double End1 = 0.0;//pq.top().second;
	
	while(!pq.empty() && End1 < l)
	{
           double currentStart = -pq.top().first;
	   double currentEnd = pq.top().second;
	   double bestEnd = 0;
	   if( currentStart > End1) break;
	   while(!pq.empty() && currentStart <= End1)
	   {
	      if( currentEnd > bestEnd )
	      {
		bestEnd = currentEnd;
	      }
	      pq.pop();
	      currentStart = -pq.top().first;
	      currentEnd = pq.top().second;
	   } 
	      End1 = bestEnd;
	      cont++;	
	}
	if(End1 < l)
	printf("-1\n");
	else
	printf("%d\n", cont);
   }
}
