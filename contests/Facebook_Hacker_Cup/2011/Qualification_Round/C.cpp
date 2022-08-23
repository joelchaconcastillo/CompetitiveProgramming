#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  for(int c = 1; c <=N; c++)
  {
    int M;
    cin >> M;
    vector<pair<string, string>> word(M);
    for(int i = 0; i < M; i++)
    {
      cin >>word[i].first;
      word[i].second=word[i].first;
      int s = word[i].first.size();
      word[i].first += string(10-s,word[i].first[s-1]);
      cout<<word[i].first<<" " <<word[i].second<<endl;
    }
    sort(word.begin(), word.end());
    cout << "Case #"<<c<<": ";
    for(int i =0; i < M; i++)cout << word[i].second;
    cout << endl;
  }
  return 0;
}
