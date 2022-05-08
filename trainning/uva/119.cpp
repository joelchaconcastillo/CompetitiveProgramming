#include <bits/stdc++.h>
using namespace std;

int main()
{
   int S, cont=0;
   while(scanf("%d", &S) != EOF)
   {
	map<string, int> group;
	if(cont++ !=0) cout <<endl;	
	vector<string> names;
	for(int i = 0; i  < S; i++){
	   string name;
	   cin >> name;
	   group[name] = 0;
	   names.push_back(name);
	}
	for(int i = 0; i  < S; i++){
	   string name;
	   int quantity, linked;
	   cin >> name >> quantity >> linked;
	   for(int j = 0; j < linked; j++)
	   {
	      string namelinked;
		cin >> namelinked;
	      group[namelinked] += floor(quantity/linked);
	      group[name] -= floor(quantity/linked);
	   }
	}
	for(int i = 0; i < names.size(); i++)
	cout << names[i] << " "<<group[names[i]] <<endl;
   }
}
