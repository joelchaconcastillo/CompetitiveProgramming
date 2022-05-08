#include <bits/stdc++.h>
using namespace std;
int n = 0 ,data[3*5000];
int dist(int i, int j)
{
   double t = (data[3*i]-data[3*j])*(data[3*i]-data[3*j]);
   t += (data[3*i+1]-data[3*j+1])*(data[3*i+1]-data[3*j+1]);
   t += (data[3*i+2]-data[3*j+2])*(data[3*i+2]-data[3*j+2]);
   return (int)sqrt(t);
}
int main()
{
   while(cin >> data[3*n] >> data[3*n+1] >> data[3*n+2])
   {
	int &a = data[3*n], &b = data[3*n+1] , &c=data[3*n+2];
	if(!a && !b && !c) break;
        n++; 
   }
   set<int> data[5000];
   int f[10];
   for(int i = 0; i < n; i++)
      {
	for(int j = 0; j<n; j++)
        {
	   if(i==j) continue;
	   data[i].insert( dist(i, j));
        }
      }
}
