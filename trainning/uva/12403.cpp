#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int sum = 0;
	for(int i = 0; i < T; i++)
	{
	  string operation;
	  cin >> operation;
	  if( operation == "donate")
	  {
		 int tmp ;
		 cin >> tmp;
		 sum +=tmp;
	  }
	  else if(operation == "report")
		  cout << sum<<endl;
	}

}
