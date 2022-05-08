#include <bits/stdc++.h>
using namespace std;
int main()
{
 int L;
 while(cin >>L, L)
 {
    string line; 
    cin >>line;
    int s = line.size();
    int pos_prev = 0, mind = 1000000, prev = -1;
    for(int i = 0; i < s; i++)
    {
      
      if( line[i] !='.')
      {
 	if(prev != line[i])
	{
	  if(prev != -1)
	    mind = min(mind, abs(i-pos_prev));
	  prev = line[i];
	}
	  pos_prev = i;
      } 

      if( line[i] == 'Z')
      {
	mind = 0;
	break;
      }
    }
    cout << mind <<endl;
 }
}
