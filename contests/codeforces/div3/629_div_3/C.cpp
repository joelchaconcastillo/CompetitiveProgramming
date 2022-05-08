#include <bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin >>t;
   while(t--)
   {
      int n;
      string line;
      cin >> n;
      cin >> line;
      string a="1", b="1";
      bool unchanged = true;
      for(int i = 1; i < n; i++)
      {
	int option = line[i]-'0';
        if( option == 2 && unchanged)
	{
	   a.push_back('1');
	   b.push_back('1');
	}
	else if(option == 1 && unchanged)
	{
	   a.push_back('1');
	   b.push_back('0');
	   unchanged = false;
	}
        else if( option == 2 && !unchanged)
	{
	   b.push_back('2');
	   a.push_back('0');
	}
        else if( option == 1 && !unchanged)
	{
	   b.push_back('1');
	   a.push_back('0');
	}
	else
	{
	   b.push_back('0');
	   a.push_back('0');
	}

      }
      cout << a << "\n"<<b<<endl;
   }
   return 0;
}
