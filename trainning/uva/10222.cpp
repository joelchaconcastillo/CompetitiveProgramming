#include <bits/stdc++.h>
using namespace std;
int main(){
   string st;
   string keyboard1="qwertyuiop[]";
   string keyboard2="asdfghjkl;";
   string keyboard3="zxcvbnm,./";
   string keyboard4="`1234567890-=";
   unordered_map<char, char> dic;
   for(int i =2; i < keyboard1.size(); i++)
	dic[keyboard1[i]]=keyboard1[i-2];
   for(int i =2; i < keyboard2.size(); i++)
	dic[keyboard2[i]]=keyboard2[i-2];
   for(int i =2; i < keyboard3.size(); i++)
	dic[keyboard3[i]]=keyboard3[i-2];
   for(int i =2; i < keyboard4.size(); i++)
	dic[keyboard4[i]]=keyboard4[i-2];
   dic[' ']=' ';
   dic['/']=',';
   dic['\'']='l';
   dic['\\']='[';
   while(getline(cin, st)){
   for(auto &i:st)i=dic[i];
   cout<<st<<endl;
   }
   return 0;
}
