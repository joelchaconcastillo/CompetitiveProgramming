#include <bits/stdc++.h>
using namespace std;
int main()
{
 int B, N;
 while(cin >> B >> N, (B && N))
 {
    vector<int> reserves(B);
    for(int i = 0; i < B; i++)cin>>reserves[i];
    for(int i = 0; i <N; i++)
    {
	int d, c, v;
	cin >>d >>c >>v;
	reserves[d-1]-=v ;

	reserves[c-1]+=v ;
    }
    bool flag=true;
    for(int i = 0; i <B; i++)
    {
	    if(reserves[i] < 0) flag=false;
    }
    if(flag) cout << "S"<<endl; else cout << "N"<<endl;
 }
}
