#include <bits/stdc++.h>
using namespace std;
int mod(int a, int b)
{
  int q = (int)floor(a/(double)b);
  return a - q*b;
}
int gcd(int a, int b){ return b?gcd(b, a%b):a;}
//int gcd(int a, int b){ return b?gcd(b, mod(a, b)):a;}
int main()
{
  int n;
  while(cin>>n, n!=0)
  {
     vector<int>di;
    di.push_back(n);
    while(cin>>n, n!=0) di.push_back(n);
    int mini=di[0];//0;//INT_MAX;
//    for(auto i:di) mini=min(mini, i);
    int sgcd = abs(di[0]-mini); 
    for(int i = 1; i < di.size(); i++)
	sgcd = gcd(sgcd, abs(di[i]-mini));
    cout << sgcd<<endl;
  }
  return 0;
}
