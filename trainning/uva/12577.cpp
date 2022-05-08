#include <bits/stdc++.h>
using namespace std;
int main()
{
  string word;
  int Case = 1;
  while(cin >> word , word!="*" )
  {
    cout << "Case "<<Case++ << ": ";
    if(word == "Hajj")
       cout << "Hajj-e-Akbar"<<endl;
    else
	cout << "Hajj-e-Asghar"<<endl;

  }
}
