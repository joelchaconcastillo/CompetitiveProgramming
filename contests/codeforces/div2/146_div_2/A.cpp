#include <bits/stdc++.h>
using namespace std;

int main()
{
 string word;
 cin >> word;
 int count[300];
 memset(count, 0, sizeof count);
  int cont = 0;
 for(auto i = word.begin(); i != word.end(); i++)
  {
     if(count[*i] == 0)
	cont++, count[*i]++;
  }
 if(cont%2)
 cout << "IGNORE HIM!\n";
 else cout << "CHAT WITH HER!\n";
 return 0;
}
