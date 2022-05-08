#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  map<char, double> dd;
  dd['C']=12.01;
  dd['H']=1.008;
  dd['O']=16;
  dd['N']=14.01;
  scanf("%d", &t);
  while(t--)
  {
      char str[81];
      scanf("%s", str);
      int n = strlen(str), i=0;
      double sum=0;
      while( i < n)
      {
	char E;
	E=str[i++];
	int q=0;
	while(str[i]>='0' && str[i]<='9')
	{
	   q *=10;
	   q +=str[i]-'0';
	   i++;
	}
	if(q==0) q=1;
	sum += dd[E]*q;
      }
      printf("%.3lf\n", sum);
  }
  return 0;
}
