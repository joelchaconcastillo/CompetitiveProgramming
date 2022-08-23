#include<bits/stdc++.h>

using namespace std;
int main()
{
  string line;
//  while(scanf("%s ", line) != EOF)
  map<string, pair<int, string> > dic;
  while(getline(cin, line))
  {
  stringstream sline(line);
    string word;
     while(getline(sline, word, ' '))
    {
//	cout << line<<endl;     
     if(word[0]=='#') break;
     string line2 = word;
    transform(word.begin(), word.end(),word.begin(), ::tolower);
     sort(word.begin(), word.end());
     dic[word].first++;
     dic[word].second = line2;
    }
  }
  vector<string> list;
  for(auto i = dic.begin(); i != dic.end(); i++)
	if(i->second.first == 1)
	{
	   list.push_back(i->second.second);
	}
  sort(list.begin(), list.end());
  for(auto i = list.begin(); i != list.end(); i++)
   cout << *i <<endl;
  return 0;
}
