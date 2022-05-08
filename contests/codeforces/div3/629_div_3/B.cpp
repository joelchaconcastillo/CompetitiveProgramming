#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >>t;
  while(t--)
  {
    int n, k;
    cin >> n >> k;
    int b1 = n-2, b2, kk=0;
    
    for(; b1 >= 0 && kk < k; b1--)
       for(b2 = n-1; b2 > b1 && kk < k; b2--, kk++);
     b2++;
     b1++;
    for(int i = 0 ; i < n; i++)
    {
	   if( i != b1 && i != b2) cout << "a";
	   else cout << "b";
    }
    cout <<endl;
  }
  return 0;
}
