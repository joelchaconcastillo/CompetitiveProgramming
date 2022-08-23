#include <bits/stdc++.h>
using namespace std;
int R, C, maxsize, csize;

vector<vector<bool> > marked;
vector<vector<int> > g;
int dx[]={1,0,-1, -1, -1, 0, 1, 1, 1}, dy[]={-1, -1, -1, 0, 1, 1, 1, 0};
void bk(int x, int y){
	if(g[x][y]==0)return;
   csize++;
    marked[x][y]=true;
    for(int i = 0; i < 8; i++){
	int nextx=x+dx[i], nexty=y+dy[i];
	if( nextx<0 || nextx>=R || nexty<0 ||nexty>=C)continue;
	if(marked[nextx][nexty] || g[nextx][nexty]==0)continue;
	bk(nextx, nexty);
    }
}

int main()
{
  int T;
  cin >>T;
  for(int t = 1; t<=T; t++){
    cin>>R>>C; 
    marked.assign(R, vector<bool>(C,false));
    g.assign(R, vector<int>(C, 0));
    maxsize=0;
    for(int i = 0; i  < R; i++)
     for(int j = 0; j < C; j++)
	cin>>g[i][j];
    //starting backtraking..
    for(int i = 0; i  < R; i++){
     for(int j = 0; j <C; j++){
        if(marked[i][j])continue;
	csize=0;
        bk(i, j);
	maxsize=max(maxsize, csize);
     }
    }
    cout <<"Case #"<<t<<": "<<maxsize<<endl;
  }
  return 0;
}
