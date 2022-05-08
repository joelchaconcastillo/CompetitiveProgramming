#include <bits/stdc++.h>
using namespace std;
int main()
{
   int A,C;
   vector<int> data(100005, 0);
   while( cin >>A >> C, A > 0)
   {
      int minb=INT_MAX , maxb=INT_MIN;
      int totalsum = 0, prev=-1, prevprev;
      for(int i = 0; i  < C; i++)
      {
	cin >> data[i];
      }
	data[C] = A;
	for(int i = 0; i  < C; i++)
	{
	  totalsum += max(0, data[i+1]-data[i]);
        }
      cout << totalsum <<endl;
   }
}
