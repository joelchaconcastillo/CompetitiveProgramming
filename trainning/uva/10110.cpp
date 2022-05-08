#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  while(cin >>n)
  {
	if(n == 0) break;
	if( sqrt(n)-(int)sqrt(n)  > 0 )cout <<"no\n";
	else cout << "yes\n";
  }
  return 0;
}
