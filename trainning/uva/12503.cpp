#include <bits/stdc++.h>
using namespace std;

int main()
{
   int T;
   cin >> T;
   vector<int>  mem(100);
   for(int i = 0; i < T; i++)
   {
      int N;
      cin >> N;
      int current = 0;
      for(int j = 0; j < N ; j++)
      {
         string instruction;
         cin >> instruction;
	 if( instruction == "LEFT")
		 mem[j] = -1;
	 else if(instruction == "RIGHT")
		 mem[j] = 1;
	 else if( instruction == "SAME" )
	 {
	    string tmp;
	    int idx;
	    cin >> tmp >> idx;
	    mem[j] = mem[idx-1];
	 }
	 current += mem[j];
      }
	cout << current <<endl;
   }
}
