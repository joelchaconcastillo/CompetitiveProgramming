#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  double sum = 0.0;
  cin >>n;
  for(int i = 0; i <n; i++)
  {
    int per;
    cin >> per;
    sum += ((double)per/n);
  }
  cout.precision(10);
  cout << sum <<endl;
  return 0;
}
