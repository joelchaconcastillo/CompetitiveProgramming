#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N,M;
  cin>>N>>M;
  vector<pair<int, string>>data;
  for(int i = 0;i < M; i++)
  {
   string st;
   cin>>st; 
   if(st.size()<=N)
      data.push_back({st.size(), st});
  }
  sort(data.begin(), data.end());
  long long score=0, dotc=0, cc=0;
  vector<string> t(N, string(""));

    for(int i = 0, k=0; i <N; i++)
    {
       while(t[i].size()+data[k].second.size() < N)
       {
	 t[i] += data[k].second;
	 k++;
       } 
       t[i] += string(N-t[i].size(),'.');
    }
    for(int i = 0; i < N; i++)
    {
	cout<<t[i]<<endl;
    }
//  if(cc==M)
//  score = (1e8*2LL*N*N)/(2LL*N*N-dotc);
//  else score = ((1e8*cc)/M);
//
//  cout <<cc<<" " <<dotc<<" "<<M<<endl;
//  cout <<score<<endl;
  return 0;
}
