#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N, K, cont = 0;
  cin >> N >> K;

  for(int i = 0; i < N; i++)
  {
    int d;
    cin >> d;
    cont += ( 5-d >= K);
  }
  cout << cont/3<<endl;
  return 0;
}
