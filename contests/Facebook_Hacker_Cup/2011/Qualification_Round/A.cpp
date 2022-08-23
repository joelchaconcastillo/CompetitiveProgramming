#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  for(int c =1 ; c <=N; c++)
  {
    int x,cont=0;
    cin >> x;
    for(int a = 0; a*a <= x/2 ; a++)
    {
        int b = sqrt(x-a*a);
        if( a*a+b*b == x)
          cont++;
    }
    cout <<"Case #"<<c<<": "<< cont<<endl;
  }
  return 0;
}
