#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >>N;
  for(int i = 0; i < N; i++)
  {
     string inp;
     cin >> inp;
     if(inp == "1" || inp == "4" || inp =="78") cout << "+"<<endl;
     else if(inp[inp.size()-2] == '3' && inp[inp.size()-1] == '5')
	cout << "-"<<endl;
     else if(inp[0] == '9' && inp[inp.size()-1]=='4')
	cout << "*"<<endl;
     else if(inp[0] == '1' && inp[1] == '9' && inp[2]=='0')
	cout << "?"<<endl;
     else cout << "?"<<endl;
  }
}
