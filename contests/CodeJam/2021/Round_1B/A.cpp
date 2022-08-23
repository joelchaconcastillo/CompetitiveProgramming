#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ite;
  cin>>ite;
  for(int t =1 ; t <= ite;t++)
  {
    vector<long long> d(3);
    cin >> d[0] >> d[1] >> d[2];
    int h = 0, m=0, s=0, ns;
    long long M = (360)*(12)*1e10;
    bool f=0;
    sort(d.begin(), d.end());
    do
    {
 	long long dd = d[1]-d[0];
	if(dd<0)dd+=M; //absolute difference
        for(int i =0; i < 12; i++)
	{
	   //long long n = i*3600*1e9+dd;
	   long long n = i*M+dd;
	   if(n%11==0)
           {
	       n /=11;
	       long long sh = d[0]-n;
	       if(sh<0)s+=M;
	       if( d[0] == (n+sh)%M && d[1] == (12*n+sh)%M && d[2] == (720*n+sh)%M) 
	       {
	               ns= n%1'000'000'000, n/=1'000'000'000, s=n%60, n/=60, m=n%60, n/=60, h=n;
	       if(h<12){ f=1;break;}
	       }
	   }
	   if(f)break;
	}
    }while(!f && next_permutation(d.begin(), d.end()));

    cout <<"Case #"<<t<<": " << h << " " <<m << " " << s << " " << ns<<endl;
  }
 return 0;
}
