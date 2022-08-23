#include<bits/stdc++.h>
using namespace std;
int main()
{
   char song[17][10] = {"Happy","birthday", "to","you", "Happy", "birthday", "to" ,"you", "Happy","birthday","to","Rujia","Happy","birthday","to","you"};
   char names[101][101];
   int Nnames;
   cin >> Nnames; 
   for(int i = 0; i < Nnames; i++)
	cin >> names[i];
   for(int i = 0; i < Nnames+16-(Nnames%16); i++)
   {
	cout << names[i%Nnames] << ": "<< song[i%16] << endl;
   }
}
