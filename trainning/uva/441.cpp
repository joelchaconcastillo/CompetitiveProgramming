#include <bits/stdc++.h>
using namespace std;
int main()
{
  int s;
  bool flag = false;
  while(scanf("%d", &s), s > 0)
  {
    if(flag) printf("\n");
    flag=true;
     vector<int> S(s);
    for(int i = 0 ; i < s; i++) scanf("%d ", &(S[i]));	
    for(int a = 0; a < S.size()-5; a++)
     for(int b = a+1; b < S.size()-4; b++)
      for(int c = b+1; c < S.size()-3; c++)
       for(int d = c+1; d < S.size()-2; d++)
        for(int e = d+1; e < S.size()-1; e++)
         for(int f = e+1; f < S.size(); f++)
	    printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);

  }
}
