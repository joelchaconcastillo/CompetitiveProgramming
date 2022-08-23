#include <bits/stdc++.h>
using namespace std;
int main()
{
   int N;
   cin >>N;
   cout << "Lumberjacks:"<<endl;
   for(int i = 0; i < N; i++)
   {
 	int prev, current;
	cin >>prev >> current;
        short sign  = (prev < current)?1:-1;
	bool flag = true;
	for(int j = 0; j < 8;j++)
	{
	  prev= current;
	  cin >> current;
	  if(!flag)continue;
//	  if(  sign*prev < sign*current ) 
	  if( !((sign*(prev-current)) < 0))
	   flag=false;
	}
	if(flag)
	cout << "Ordered"<<endl;
	else
	cout << "Unordered"<<endl;
   }
}
