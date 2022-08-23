#include <bits/stdc++.h>
using namespace std;
bool isvowel(char c)
{
  c = tolower(c);
  return (c=='a' || c == 'e' || c=='i' || c=='o' || c=='u');
}
bool isconsonant(char c)
{
   c = tolower(c);
   if(isvowel(c))return false;
   return ( c>='a' && c<='z' );
}
int main()
{
  string s, out, in="";
  while(getline(cin, s)) in = in+s+"\n";
  string record="";
    for(auto i:in)
    {
//	char i = s[j];
	if(!isvowel(i) && !isconsonant(i))
	{
	   if(!record.empty())
	   {
	     if(isvowel(record[0])) record +="ay";
	     else if(isconsonant(record[0]))
	     {
		record = record +record[0]+"ay";// record[0]+"ay"; 
	        record = record.substr(1);
	     }
	   }
	   record +=i;
	   out += record;
	   record="";
	}
	else record +=i;
    }
	out.pop_back();
  cout << out<<endl;
  return 0;
}
