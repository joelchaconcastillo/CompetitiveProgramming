#include <bits/stdc++.h>
#define MAX_N 101
using namespace std;
int main()
{
  int N, ite=1;
  while(cin >> N)
  {
   map<string, int> dic;
   map<int, string> idic;
    for(int i = 0; i < N; i++)
    {
      string str;
      cin >> str;
      dic[str] = i;
      idic[i] = str;
    }
    vector<vector<int> > adj(N);
    vector<int> incomming_cont(N, 0);
    int M;
    cin >> M;
    for(int i = 0; i < M ; i++)
    {
      string str1, str2;
      cin >> str1 >> str2;
      adj[dic[str1]].push_back(dic[str2]);
      incomming_cont[dic[str2]]++;
    }
    queue<int>q;
    vector<int>order_d;
    for(int i = 0; i <N; i++)
	if(incomming_cont[i]==0)
	{
	  q.push(i);
	  break;
	}

    while(!q.empty())
    {
       int u = q.front(); q.pop();
       order_d.push_back(u);
	incomming_cont[u]--;
       for(auto i:adj[u])
	  incomming_cont[i]--;
       for(int i =0; i < N; i++)
	{
	   if(incomming_cont[i]==0)
	   { 
	      q.push(i);
	      break;
	    }
	}
    } 
    cout << "Case #"<<ite++<<": Dilbert should drink beverages in this order:";
    for(auto i:order_d) cout <<" "<< idic[i];
	cout <<"."<<endl<<endl;
    string str;
    getline(cin, str);
  }
  return 0;
}
