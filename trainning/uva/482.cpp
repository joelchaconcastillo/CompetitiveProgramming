#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
     string st;
     cin.ignore();
     getline(cin ,st);
     getline(cin ,st);
     stringstream in(st);
     vector<int> inorder;
     int p;
     while(in>>p) inorder.push_back(p);
     vector<string> order(inorder.size());
     for(auto i:inorder) cin>> order[i-1];
     for(auto i:order) cout<<i<<endl;
     if(t)cout<<endl;
  }
  return 0;
}
