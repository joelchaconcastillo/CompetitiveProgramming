#include <bits/stdc++.h>
using namespace std;
int main()
{
   int N, B, H, W;
   int START = 100000000;
   while( scanf("%d %d %d %d", &N, &B, &H, &W) != EOF)
   {
	int totalmincost = START;
	for(int nh = 0; nh < H; nh++)
	{
	   int currentcostbyone;
	   scanf("%d\n", &currentcostbyone);
	   for(int nw = 0 ; nw < W; nw++)
	   {
		int navailable;
		scanf("%d", &navailable);
		if( navailable >= N && currentcostbyone*N <= B)
		{
		   if( currentcostbyone*N  < totalmincost)
		       totalmincost = currentcostbyone*N;
		}
	   }
	}
	if( totalmincost != START)
	cout << totalmincost <<endl;
	else
	cout << "stay home"<<endl;
   }
}

