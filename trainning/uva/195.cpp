#include <bits/stdc++.h>

using namespace std;
string tranform_w(string &w)
{
  string w2 = w;
  for(int i = 0; i < w.size(); i++)
  {
    int a = (int) w[i]  - 'A';
    int d = 'a' - 'A';
    a = 2*(a%d)+(a/d);
    w2[i] = a;
  }
  return w2;
}
string tranform_inv(string &w)
{
  string w2 = w;
  for(int i = 0; i < w.size(); i++)
  {
    int a = (int) w[i];
    a = (a%2)*32 + a/2 ;
    w2[i] = (char)a+65;
  }
  return w2;
}
int main()
{
  int K;
  string word;
  scanf("%d\n",&K);
  for(int i = 0; i < K; i++)
  {
    vector<string> l;
    cin >> word;
    sort(word.begin(), word.end());
	do{
	   l.push_back(tranform_w(word));
	}
    while(next_permutation(word.begin(), word.end()));
    sort(l.begin(), l.end());
    for(auto i = l.begin(); i != l.end(); i++)
    {
	cout << tranform_inv(*i) <<endl;
    }
  }
  return 0;
}
