#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  for(int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    if( (n/2)%2 != 0 ) cout << "NO"<<endl;
    else
    {
	cout << "YES"<<endl;
	int sum1 = 0, sum2 = 0;
	//even numbers..
	for(int d = 1; d <= n/2; d++){sum1+=d*2; cout << d*2<< " " ;}
	//odd numbers..
        for(int d = 1; d <= n/2 - 1; d++) {sum2 += d*2-1; cout << d*2-1<< " ";}

	for(int d = (n+1)/2-1;; d++) if( sum2+(d*2-1) == sum1) {cout << d*2-1; break;}
	cout <<endl;
    }
  }
  return 0;
}
