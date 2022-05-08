#include <bits/stdc++.h>
using namespace std;
int rd[]={1, 0, -1, 0}, cd[]={0, -1, 0, 1}, ri[]={0,0,0,0}, ci[]={0,0,0,0}, ti[]={0,0,0,0};
int n, m, cont;
bool marked[8][8];
int points[8][8];
bool split(int x, int y){
   static int v[9], i, j;
   //left vertical line
    v[0] = x-1 < 0 || y-1 < 0 || marked[x-1][y-1];
    v[1] = x-1 < 0 || marked[x-1][y];
    v[2] = x-1 < 0 || y+1 >= m || marked[x-1][y+1];
    //botto horizontal mline
    v[3] = y+1 >= m || marked[x][y+1];
    //right vertical line
    v[4] = x+1 >= n || y+1 >= m || marked[x+1][y+1];
    v[5] = x+1 >= n || marked[x+1][y];
    v[6] = x+1 >= n || y-1 < 0 || marked[x+1][y-1];
    v[7] = y-1 < 0 || marked[x][y-1];
    v[8] = v[0];
    for(i = 0, j = 0; i < 8; i++)
        if(v[i] != v[i+1])
            j++;
    return j >= 4;
}
void bk(int r, int c, int d)
{
   if(points[r][c]!=0 && points[r][c]!=d)return;
   for(int i = 0; i < 4; i++)
   {
      if(ti[i]==d && (r!=ri[i] || c!=ci[i]))return;
      if(d < ti[i] && abs(r-ri[i])+abs(c-ci[i]) > ti[i]-d)return;
   }
   if(split(r, c))
        return;
   if(d==m*n && r==0 && c==1){
     cont++; 
     return;
   }
   for(int i = 0; i < 4; i++)
   {
     int nr=r+rd[i], nc=c+cd[i]; 
     if(nr<0 || nc<0||nr>=n || nc>=m)continue;
     if(marked[nr][nc])continue;
     marked[nr][nc]=true;
     bk(nr, nc, d+1);
     marked[nr][nc]=false;
   }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int TC=1;
   while(cin>>n>>m)
   {
      if(n==0 && m == 0) break;
      memset(points, 0, sizeof points);
      memset(marked, false, sizeof marked);
      for(int i = 0; i< 3; i++){
        cin>>ri[i]>>ci[i];
        ti[i] = floor(((i+1.0)/4.0)*(n*m));
	points[ri[i]][ci[i]]=ti[i];
      }
      points[0][1]=n*m;
      ti[3] = n*m;
      ri[3] = 0;
      ci[3] = 1;
      cont = 0;
      marked[0][0]=true;
      bk(0,0,1);
      cout <<"Case "<<TC++<<": "<<cont<<endl;
  }
   return 0;
}
