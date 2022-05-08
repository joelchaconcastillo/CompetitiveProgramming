#include <bits/stdc++.h>
#define MAX_N 100006
using namespace std;

int main()
{
  long long n, q, f1, f2, a, b, l, r;
  long long d[MAX_N], f[MAX_N], df[MAX_N];
  memset(f, 0, sizeof f);
  memset(d, 0, sizeof d);
  memset(df, 0, sizeof df);
  cin >> n >>q >>f[1]>>f[2]>>a>>b;
  for(int i = 1; i <= n; i++) 
  {
    cin>>d[i];
//    if(i==1) dif[i] = d[i];
//    else dif[i] = d[i]-d[i-1];
  }
  for(int i = 3; i <= n; i++) 
    f[i] = a*f[i-2] + b*f[i-1];

  for(int i = 0; i < q ; i++)
  {
    cin>>l>>r;
    df[l]++;
    df[r+1]--;
  } 
  for(int i = 0; i  <= n; i++)
  {
	cout << df[i]<< " ";
//        df[i] +=df[i-1];
//	d[i] += df[i]*f[i];
//        d[i]%= (1000000007);
//        cout << d[i] <<" ";
  }

  cout <<endl;
  return 0;
}
