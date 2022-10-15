/*
 N days, M participants, P id john
 
Minimizer daily steps on each day
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int t=1; t<=T; t++){
        int M, N,P;
        cin>>M>>N>>P;
        vector<vector<int>>A(M, vector<int>(N, 0));
        for(int i =0 ; i < M; i++){
            for(int j = 0 ; j < N; j++){
                cin>>A[i][j];
            }
        }
        long long total=0;
        for(int j = 0; j < N; j++){
            int maxdif = 0;
            for(int i = 0 ; i < M ; i++){
                if(i+1==P)continue;
                maxdif=max(maxdif, max(0, A[i][j]-A[P-1][j]));
            }
            total+=maxdif;
        }
        cout << "Case #"<<t<<": "<< total <<endl;
    }
    return 0;
}
