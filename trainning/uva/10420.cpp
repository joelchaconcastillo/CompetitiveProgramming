#include <bits/stdc++.h>
using namespace std;
int main()
{
 int N;
  
 string line;
 getline(cin, line);
 stringstream(line) >> N;
 map<string, int> dic;
 for(int i = 0; i < N ; i++)
 { 
   getline(cin, line);
   stringstream ss(line);
   string tmp;
   ss >> tmp;
   dic[tmp]++;
 }
// for(pair<string, int> item : dic)
 for(map<string ,int>::iterator it = dic.begin(); it != dic.end() ;it++)
 {
  cout << it->first << " " <<it->second<<endl;
 }
 return 0;
}
