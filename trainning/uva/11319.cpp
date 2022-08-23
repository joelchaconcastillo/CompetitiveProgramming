/*
 * Warning!! it should take into account unsigned long long instead just long long
 * */
#include <bits/stdc++.h>
#define eps 1e-7
int n;
using namespace std;
struct AugmentedMatrix{
   double mat[10][10];
};
struct ColumnVector{
  double vec[10];
};
AugmentedMatrix Aug;
ColumnVector x;
bool GaussianElimination(){
   for(int j =0; j < n-1; j++){
      int l = j; 
      for(int i =j+1; i< n; i++) if( fabs(Aug.mat[l][j])  < fabs(Aug.mat[i][j])) l=i; //max abs row.. numeric stability
      for(int k = j; k <= n; k++)swap(Aug.mat[j][k], Aug.mat[l][k]);
      if(fabs(Aug.mat[l][l]) < eps)return false;
      for(int i=j+1; i < n; i++)
	  for(int k = n; k >=j; k--)
		  Aug.mat[i][k] -= Aug.mat[j][k]*Aug.mat[i][j] / Aug.mat[j][j];
   }
   for(int j = n-1; j>=0; j--){
      double t=0.0;
      for(int k = j+1; k <n; k++) t += Aug.mat[j][k]*x.vec[k];
      x.vec[j] = (Aug.mat[j][n] - t)/Aug.mat[j][j];
   }
   return true;
}
unsigned long long f(unsigned long long x, vector<unsigned long long> &a){
   unsigned long long sum = 0, base=1;
   for(int i = 0; i < n; i++){
      sum += base *a[i];
      //sum += powl(x, i) *a[i]; //it also works!
      base*=x;
   }
   return sum;
}
int main(){
   int N;
   cin>>N;
   while(N--){
     n=7;
     vector<double> seq(1500);
     vector<unsigned long long> seqll(1500);
     for(int i = 0; i < 1500; i++) cin>>seq[i], seqll[i]=seq[i]; 
     for(int i = 0; i < n; i++){
	     for(int j =0; j <n; j++)Aug.mat[i][j]=pow(i+1, j);
	     Aug.mat[i][n]=seq[i];
     }
     if(!GaussianElimination()){
       cout << "This is a smart sequence!"<<endl;
       continue;
     }
     bool hassol=true;
     vector<unsigned long long> s(n);
     for(int i = 0; i < n; i++){
	s[i] = (unsigned long long)llround(x.vec[i]);
	if(s[i]<0 || s[i]>1000){
	       	hassol=false;
		break;
	}
     }
     if(!hassol){
     cout << "This is a smart sequence!"<<endl;
       continue;
     } 
     for(int i = 0;  i< 1500; i++){
        if( f(i+1, s) != seq[i]){
	  hassol=false;
	  break;
	}
     }
     if(!hassol){
     cout << "This is a smart sequence!"<<endl;
       continue;
     } 

     for(int i = 0; i < 7; i++){
	     cout << s[i];
	     if(i<6)cout <<" ";
     }
     cout <<endl;
	
   }
   return 0;
}
