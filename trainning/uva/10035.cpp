#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a, b;
  while(cin >> a >> b)
  {
    if(a==0 && b==0) break;
    int cont = 0, s=0;
    while(a > 0 || b >0)
    {
//	cout << a << " " <<b <<endl;
       s = (a%10 + b%10+s)/10; 
       a /=10;
       b /=10;
      cont +=s;
    }
    if(cont==0) cout << "No carry operation."<<endl;
    else if(cont==1)cout << cont<<" carry operation."<<endl;
    else cout << cont<<" carry operations."<<endl;
  }
  return 0;
}
