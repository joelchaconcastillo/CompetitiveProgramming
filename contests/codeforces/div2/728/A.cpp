#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >>t;
  while(t--)
  {
    int n;
    cin >>n;
    vector<int> a(n);
    for(int i = 0;i < n; i++)a[i]=i+1;
    for(int i = 0; i < n-(n%2); i+=2) iter_swap(a.begin()+i, a.begin()+i+1);
    if(a.size() % 2)
    {
      iter_swap(a.end()-2, a.end()-1);
    }

    for(int i = 0; i < n ;i++) cout << a[i]<<" ";
    cout <<endl;
  }
  return 0;
}
