#include <bits/stdc++.h>
using namespace std;
int main()
{
  int distance =0;
  for(int i = 0; i < 5; i++)
  {
     for(int j = 0; j < 5; j++)
     {
	int n;
        cin >>	n;
	if( n == 1 )  distance = abs(i-2)+abs(j-2);
     }
  }
  cout << distance <<endl;
  return 0;
}
