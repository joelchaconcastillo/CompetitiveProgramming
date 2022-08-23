#include <bits/stdc++.h>
using namespace std;
int main(){
   string line;
   int count=0;
   while(getline(cin, line)){
	if(line.back()=='?')continue;
	int a=stoi(line);
	int pos=0;
	char sign='+';
	while(pos<line.size() && line[pos]!='+' && line[pos]!='-')pos++;
	sign=line[pos];
	pos++;
        int b=stoi(line.substr(pos));
	while(pos<line.size() && line[pos]!='=')pos++;
	pos++;
	int c=stoi(line.substr(pos));
	if(a+b==c && sign=='+') count++;
	else if(a-b==c && sign=='-') count++;
   }
   cout<<count<<endl;
   return 0;
}
