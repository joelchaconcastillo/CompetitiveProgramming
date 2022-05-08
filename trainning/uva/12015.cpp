#include <bits/stdc++.h>
using namespace std;
int main()
{
   int T;
   scanf("%d", &T);
   for(int i = 0; i < T; i++)
   {
      int maxidx = -1;
      vector<vector<string> > dat(101);
       string tmp;
      for(int j = 0; j < 10; j++)
      {
	int relevance;
	cin >> tmp >> relevance;
	dat[relevance].push_back(tmp);
	maxidx = max(maxidx, relevance);
      }
	cout << "Case #"<<i+1<<":"<<endl;
      for(int j = 0; j < dat[maxidx].size();j++)
	{
	   cout << dat[maxidx][j] <<endl;
	}
   }

}
