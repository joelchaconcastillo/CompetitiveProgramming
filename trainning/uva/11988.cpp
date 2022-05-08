#include <bits/stdc++.h>
using namespace std;
int main()
{
  string str1;
  while( cin >> str1) 
  {
    list <string> d; 
    bool flag_back = false; 
    string current_word;
    str1.push_back(']');
    for(int i = 0; i < str1.size(); i++)
    {
	if( str1[i] != '[' && str1[i] != ']')
	current_word.push_back(str1[i]);
	if( str1[i] == '[' || str1[i] == ']')
	{
	  if(flag_back) d.push_back(current_word);
	  else d.push_front(current_word);
	  current_word.clear();
	}
	if( str1[i] == '[')
	{
	 flag_back=false;
	}
	else if( str1[i] == ']')
	{
	 flag_back=true;
	}
    }
    
    for(auto a = d.begin(); a != d.end(); a++)
        cout <<  *a;
    cout << endl;
  }
  return 0;
}
