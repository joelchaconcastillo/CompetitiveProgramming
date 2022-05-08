#include <bits/stdc++.h>
using namespace std;

int main()
{
  int d;
  int rank[5];
  rank[0] = 0 ;
  rank[1] = 3;
  rank[2] = 1;
  rank[3] = 2;

  cin >>d;
  int maxr = -1, maxi=0;
  for(int i = 0; i <= 2; i++)
  {
	int r = rank[(d+i)%4];
 	if( maxr < r )
	{
	  maxr = r;
	  maxi = i;
	}
  }  
  char c;
  if(maxr == 0) c = 'D';
  else if(maxr == 1) c = 'C';
  else if(maxr == 2) c = 'B';
  else if(maxr == 3) c = 'A';
  
  cout << maxi << " "<<c<<endl;
  return 0;
}
