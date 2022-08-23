#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int i = 1; i <=T; i++)
    {
        int N, T;
        string st;
        cin >>N >> T>>st;
        int cont = 0;
        for(int j = 0; j < N/2; j++)
        {
            if(st[j] != st[N-j-1])cont++;
        }
        int v;
        if(T>cont) v=T-cont;
        else v = cont-T;
        cout << "Case #"<<i<<": "<<v<<endl;
    }
    return 0;
}
