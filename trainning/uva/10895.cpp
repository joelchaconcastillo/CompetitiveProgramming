#include <bits/stdc++.h>
using namespace std;
int main()
{
  int m, n;


  while(scanf("%d %d\n", &m, &n) != EOF)
  {

  vector< vector< pair<int, int> > > A(n);
    for(int i = 0; i < m; i++)
    {
       int r;
       vector<int> index, values;
       scanf("%d ", &r); 
       if( !r){
	       scanf("\n\n");
	       continue;
       }
       for(int j = 0; j < r; j++)
 	{
	  int idx;
          scanf("%d ", &idx);
	  index.push_back(idx);
	}
       scanf("\n");
       for(int j = 0; j < r; j++)
       {
	  int val;
          scanf("%d ", &val);
	  values.push_back(val);
       }
       scanf("\n");

       for(int j = 0; j < r; j++)
       {
        A[index[j]-1].push_back(make_pair(i, values[j]));
       }
    }  
    printf("%d %d\n", n, m);
    for(int i = 0; i < n; i++)
    {
	if( A[i].empty())
	{
		printf("0\n\n");
		continue;
	}
	
	printf("%d ", (int)A[i].size() );

	for(int j = 0; j < A[i].size(); j++)
	{
		if(j < A[i].size()-1)
	   printf("%d ", A[i][j].first+1);
		else
	   printf("%d", A[i][j].first+1);

	}
	printf("\n");
        for(int j = 0; j < A[i].size(); j++)
	{
		if(j < A[i].size()-1)
	   printf("%d ", A[i][j].second);
		else
	   printf("%d", A[i][j].second);
	}
	printf("\n");
    }
  }
}
