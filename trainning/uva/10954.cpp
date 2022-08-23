#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N;
   while(scanf("%d", &N), N>0)
   {
      priority_queue <int> pq;
      for(int i = 0; i < N; i++)
      {
	int t;
	scanf("%d", &t);
	pq.push(-t);
      }
      int sum =  0;//(!pq.empty())?-pq.top():0;
      while(!pq.empty()) 
      {
	int a, b;
	a = -pq.top();
	pq.pop();
	 b = -pq.top();
	 pq.pop();
	sum +=a+b;
	if(pq.empty())break;
	pq.push(-(a+b));
      }
      printf("%d\n", sum);
   }
   return 0;
}
