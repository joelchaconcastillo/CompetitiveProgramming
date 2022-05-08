#include <bits/stdc++.h>
using namespace std;
int main()
{
 int T, N;
 int cont[10];
 cin >> T ;
 while(T--)
 {
    memset(cont, 0, sizeof cont);
    cin >> N;
    for(int i = 1; i <=N; i++)
    { 
	int t = i;
	while(t){cont[t%10]++; t/=10;}
    }
    for(int i = 0; i < 9; i++) cout << cont[i]<<" ";
    cout <<cont[9]<<endl;
 }
 return 0;
}
