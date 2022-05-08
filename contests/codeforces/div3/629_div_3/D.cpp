#include <bits/stdc++.h>
using namespace std;
int main()
{
  int q;
  cin >> q;
  while(q--)
  {
     int n, prevani, ani, lascol =  1;
     cin >>n;
     cin >> ani;
     vector<int> animals;
     unordered_map<int, int>cols;
     cols[ani] = lascol;
     animals.push_back(cols[ani]);
     lascol++;
     prevani = ani;
     n--;
     while(n--)
     {
 	cin >>ani;
	if( cols.find(ani) == cols.end())
	{
	  cols[ani] = lascol;
	  lascol++;
	}
	animals.push_back(cols[ani]);
	prevani = ani;
     }
	cout << lascol-1 <<endl;
        for(int i = 0; i < animals.size(); i++)cout << animals[i] << " ";
	cout << endl;
  }
  return 0;
}
