#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int A,B;
	while(cin>>A>>B){
		if(A==0 && B==0)break;
		set<int>Alice, Betty;
		for(int i = 0 ; i< A; i++){
			int d;
			cin>>d;
			Alice.insert(d);
		}
		for(int i = 0 ;i < B; i++){
			int d;
			cin>>d;
			Betty.insert(d);
		}
		int N1=0, N2=0;
		for(auto i:Alice){
		   N1+=(Betty.count(i)==0);
		}
		for(auto i:Betty){
		   N2+=(Alice.count(i)==0);
		}
		cout <<min(N1, N2)<<endl;

	}
   return 0;
}
