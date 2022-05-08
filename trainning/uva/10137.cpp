#include <bits/stdc++.h>
using namespace std;
int data[1001];
int main()
{
  int N;
  while(cin >> N)
  {
    if(N==0) break;
    double ave = 0.0;
    for(int i = 0; i < N; i++){
	double t; 
	int t1, t2;
	scanf("%d.%d", &t1, &t2);
	data[i] = t1*100+t2;
//	cin >>t; 
//	data[i] = t*100;//trunc(t*1000)/10; 
	ave +=data[i];
    }
    ave /=N;
    long long int d1 =0, d2=0;
    for(int i = 0; i < N; i++)
    {
       d1 += max(0LL, (long long int)(ave-data[i]));
       d2 += max(0LL, (long long int)(data[i]-ave));
    }
	cout << "d1 "<<d1<<" d2 "<<d2<<endl;
      double r = ((d1>d2)?d1:d2);
      cout <<fixed<<setprecision(2)<<"$"<<r/100.0 <<endl;
  }
  return 0;
}
