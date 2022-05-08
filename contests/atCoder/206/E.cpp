#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){ return (b)?gcd(b, a%b):a; }
int main(){
	bitset<1000002>b;
	b.set();
	long long l,r;
	cin >>l >>r;
	b[0]=b[1]=0;
	long long sum = 0;
	for(long long i =2; i <=r; i++)
	{
	   if(!b[i])continue;
	   long long cont = 0;
   	   for(long long j = 2*i; j<=r; j+=i)
	   {
		b[j]=0;
		if(j>=l && j<=r) cont++;
	   }
	   sum +=cont*(cont-1);
	}
	for(long long i=l; i <=r; i++)
	{
	   if(b[i])continue;
//	   for(long long j=2*i; j<=r;j+=i)
//		   sum-=2;
	   sum -= 2*((r-i-1)/i);
	}
	cout << sum<<endl;
   return 0;
}
