#include <bits/stdc++.h>
using namespace std;
int main()
{
   string line;
   int k = 0;
   cin >> k;
      getline(cin, line);
   for(int j = 0; j < k; j++)
   {
      getline(cin, line);
      int s = line.size(), M=0, F=0;
      for(int i = 0; i < s; i++)
      {
	if( line[i] == 'M') M++;
	if(line[i] == 'F') F++;
      }
	if(s <=2) cout << "NO LOOP"<<endl;
	else if(M==F) cout << "LOOP"<<endl;
	else if(M!=F) cout <<"NO LOOP" <<endl;
   }
}
