#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin>>T;
  while(T--){
    int n;
    cin>>n;
    vector<long long> data(n);
    for(int i = 0; i < n ;i++)cin>>data[i];
    sort(data.begin(), data.end());
    long long rem=data[0], maxmin=data[0];
    for(int i =1; i <n;i++){
	data[i] -=rem;
	rem += data[i];
	maxmin = max(maxmin, data[i]);
    }
    cout << maxmin<<endl;

  }
  return 0;
}
