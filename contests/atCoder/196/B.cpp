#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;
   cin>>s;
   int idx = 0;
   while(idx < s.size() && s[idx] !='.') idx++;
   idx++;
   cout <<s.substr(0, idx-1) <<endl;

   return 0;
}
