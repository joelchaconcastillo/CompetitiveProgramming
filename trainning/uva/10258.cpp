#include <bits/stdc++.h>
using namespace std;
#define C 101
#define P 11
int Penalization[C*P*2];
int sucess[C];
int score[C];
int main()
{
  string input;
  int n;
  cin >> n;
  getline(cin, input);
  getline(cin, input);
  for(int z = 0; z<n; z++)
  {
	if(z>0)
    cout <<endl;
    memset(Penalization, 0, sizeof Penalization);
    memset(sucess, 0, sizeof sucess);
    memset(score, 0, sizeof score);
    vector<bool> id_c(C, false);
    while(true)
    {
       getline(cin, input);
       if(input.empty())break;	
       istringstream st(input);
       int c, p, t;
       char L;
       st >> c >> p >> t >> L;
	id_c[c]=true;	
	if(Penalization[c*P+p]==-1) continue;
       if( L == 'I')
       {
	   Penalization[c*P + p]+=20;
       }
       else if( L == 'C')
       {
	   sucess[c]++;
	   score[c] += Penalization[c*P+p]+t;
	   Penalization[c*P+p]=-1;
       }
    }
    priority_queue< pair<int, pair<int, int>>> pq;
    vector<pair<int, int>>d;
    for(int i = 0; i < C; i++) if(id_c[i]>0) pq.push(make_pair(sucess[i], make_pair(-score[i], -i)));
    while(!pq.empty())
    {
	cout <<-pq.top().second.second<<" " <<pq.top().first << " " <<-pq.top().second.first<<endl;
	pq.pop();
    }
    
  }
  return 0;
}
