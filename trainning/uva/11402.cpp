#include <bits/stdc++.h>
using namespace std;

vector<int> treedata, LZ, len;
string Pirates;
const int maxn =  1024010;

void buildTree(int node, int L, int R)
{
   if( L == R ) 
   {
	treedata[node] = Pirates[L]-'0';// (Pirates[L]== '1')?1:0;
	len[node] = 1;
	LZ[node] = -1;
         return;
   }
   int left = node<<1;
   int right = left+1;
    buildTree(left, L, (L+R)/2);
    buildTree(right, (L+R)/2 + 1, R);
    treedata[node] = treedata[left] + treedata[right];
    len[node] = R-L+1;
    LZ[node] = -1;
}
void setLZ(int node, int s)
{
 if(s == 2)
 {
    if(LZ[node] == 0) LZ[node] = 1;
    else if(LZ[node] == 1) LZ[node] = 0;
    else if(LZ[node] == 2) LZ[node] = -1;
    else if(LZ[node] == -1) LZ[node] = 2;
 }
 else
   LZ[node] = s;
}
void ApplyLZ(int node)
{
     if(LZ[node] == 0)
        treedata[node] = 0;	     
     else if(LZ[node] == 1)
        treedata[node] = len[node]; 
     else if(LZ[node] == 2)
        treedata[node] = len[node] - treedata[node]; 
     else return;
   ///updating the children....
      setLZ(node <<1, LZ[node]);
      setLZ((node <<1)+1, LZ[node]);
      LZ[node] = -1;

}
int QueryLZ2(int node, int L, int R, int i, int j)
{
  ApplyLZ(node);
  if( L == i && R == j)
     return treedata[node];
  if( i > j) return 0;
  int M = (L+R)/2;
  int p1 = QueryLZ2(node << 1, L, M, i, min(j, M) );
  int p2 = QueryLZ2((node << 1)+1, M+1, R, max(i, M+1), j);
   treedata[node] = treedata[node <<1] + treedata[(node<<1)+1];
  return p1+p2;
}
int QueryLZ(int node, int L, int R, int i, int j)
{
  ApplyLZ(node);
  if( L >= i && R <= j)
     return treedata[node];
  if( i > R || j<L ) return 0;
  int M = (L+R)/2;
  int p1 = QueryLZ(node << 1, L, M, i, j);
  int p2 = QueryLZ((node << 1)+1, M+1, R, i, j);
   treedata[node] = treedata[node <<1] + treedata[(node<<1)+1];
  return p1+p2;
}
void UpdateLZ2(int node, int L, int R, int i, int j, int s)
{
   if( L == i && R == j)
     setLZ(node, s);  //set the lazy state to exact fitted ranges
   ApplyLZ(node); 
   if( L == i && R == j) return;
   if( i  > j ) return;
   else{

     int M = (L+R)/2;
     UpdateLZ2(node << 1, L, M, i, min(j, M), s);
     UpdateLZ2( (node << 1)+1, M+1, R, max(i, M+1), j, s);
     treedata[node] = treedata[node<<1] + treedata[(node<<1)+1];
   }
}
void UpdateLZ(int node, int L, int R, int i, int j, int s)
{
   if( L >= i && R <= j)
     setLZ(node, s);  //set the lazy state to exact fitted ranges
     ApplyLZ(node); 
   if( L >= i && R <= j)return;
   else
   if( i > R || j<L ) return;
   else{

     int M = (L+R)/2;
     UpdateLZ(node << 1, L, M, i, j, s);
     UpdateLZ( (node << 1)+1, M+1, R, i, j, s);
     treedata[node] = treedata[node<<1] + treedata[(node<<1)+1];
   }
}
int main()
{
   int N;
   scanf("%d\n", &N);
   treedata.resize(5*maxn, 0);
   LZ.resize(5*maxn, -1);
   len.resize(5*maxn, 0);

   for(int i = 0; i < N; i++)
   {
	printf("Case %d:\n", i+1);
	//ensambling data...
	int M; 
	scanf("%d\n", &M);
	Pirates = "";
	for(int j = 0; j < M; j++)
 	{
	   string data;
	   int rep;
	   scanf("%d\n", &rep);
	   cin >> data;
	   for(int k = 0; k < rep; k++) Pirates += data;
	}

       	buildTree(1,0,Pirates.size()-1);
	//Queries...
	int Q, cont=1;
	scanf("%d\n", &Q);
	
	for(int k = 0; k < Q; k++)
	{
	  char FLAG;
  	  int i, j;
	  scanf("%c %d %d\n", &FLAG, &i, &j);	  

	      if( FLAG == 'E' )
	 	 UpdateLZ2(1, 0, Pirates.size()-1, i, j, 0);
	      if( FLAG == 'F' )
	 	 UpdateLZ2(1, 0, Pirates.size()-1, i, j, 1);
	      if( FLAG == 'I' )
	 	 UpdateLZ2(1, 0, Pirates.size()-1, i, j, 2);
	      if( FLAG == 'S' )
		  printf("Q%d: %d\n", cont++,QueryLZ2(1, 0, Pirates.size()-1, i, j) );

	}

   }
}
