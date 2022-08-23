#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long N;
  cin>>N;
  for(long long i = 1; ; i++)
  {
     if(stoll(to_string(i)+to_string(i)) > N)
     {
	cout << i-1<<endl;
	break;
     }
  }
  return 0;
}
