#include <bits/stdc++.h>
using namespace std;
int main()
{
   vector<int> data(9);
   int num;
   while(cin >> num)
   {
      data[0]=num; 
      for(int i = 1; i < 9; i++) cin >> data[i];
      vector<int> costs(9,0), block(3,0); 
      for(int i = 0; i < 9; i++) block[i/3] += data[i];
      for(int i = 0; i < 3; i++)
      {
         for(int j = 0; j < 3; j++)
	{
	  costs[i*3+j] = block[j] - data[j*3+i];
	}
      }
     vector<int> p = {0,1,2};
     string st="BGC";
     pair<int, string > minsum(INT_MAX, "---");
     do
     {
	int sum = 0;
	string t = "   ";
	for(int i = 0; i < 3; i++) t[i] = st[p[i]];
 	for(int i = 0; i < 3; i++) sum+=costs[p[i]*3+i];
	if(sum < minsum.first ) minsum = make_pair(sum, t);
	else if(sum == minsum.first && t < minsum.second  ) minsum=make_pair(sum, t);
     }while(next_permutation(p.begin(), p.end()));

    for(int i = 0; i < 3; i++)
     cout << minsum.second[i];
 	cout << " " << minsum.first <<endl;
   }
   return 0;
}
