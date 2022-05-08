#include <bits/stdc++.h>
using namespace std;
int main()
{

  int K;
  while( scanf("%d\n", &K), K)
  {
    int aX, aY;
    scanf("%d %d\n", &aX, &aY);
    for(int i = 0; i < K ; i++)
    {
	int x,y;
	scanf("%d %d\n", &x, &y);
	x -=aX;
	y -=aY;
	if(x > 0 && y > 0) printf("NE\n");
	if(x > 0 && y < 0) printf("SE\n");
	if(x < 0 && y < 0) printf("SO\n");
	if(x < 0 && y > 0) printf("NO\n");
	if( x == 0 || y == 0) printf("divisa\n");
    }
  }
}
