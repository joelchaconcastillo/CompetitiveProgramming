#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin >> T;
    for(int t=1;t <=T;t++){
        string street;
	int n;
        cin>>n>>street;
        vector<int> dpl(n), dpr(n);
        dpl[0]=(street[0]=='1')?0:INT_MAX;
        dpr[n-1]=(street[n-1]=='1')?n-1:INT_MAX;
        for(int i = 1; i < n; i++){
            if(street[i]=='0')dpl[i]=dpl[i-1];
             else dpl[i]=i;
             
            if(street[n-i-1]=='0') dpr[n-i-1]=dpr[n-i];
             else dpr[n-i-1]=n-i-1;
             
        }
        long long sm=0;
        for(int i = 0; i < street.size(); i++)
        {
            sm += min(  abs(i-dpl[i]), abs(i-dpr[i]));
        }
        cout << "Case #"<<t<<": "<<sm<<endl;
    }
    return 0;
}
