#include<bits/stdc++.h>
using namespace std;
int main()
{
   int C;
   cin >> C;
   for(int i = 0; i < C; i++)
   {
	   if( i!=0)cout <<endl;
	int W;
	cin >> W;
	int y1, y2;
	int first= 0;
	cin >> y1 >> y2;
	first = abs(y1-y2);
	bool flag = true;
	for(int j = 0; j < W-1; j++)
	{
	   cin >> y1 >> y2;
	   int current= abs(y1-y2);
	   if( first != current)
	   {
		flag = false;
	   }
	}
	if(flag) cout << "yes"<<endl;
	else cout << "no"<<endl;
   }
}
