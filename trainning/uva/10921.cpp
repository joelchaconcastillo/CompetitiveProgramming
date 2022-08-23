#include <bits/stdc++.h>
using namespace std;
int main(){
  string st;
  unordered_map<char, char> dic;
  dic['A']=dic['B']=dic['C']='2';
  dic['D']=dic['E']=dic['F']='3';
  dic['G']=dic['H']=dic['I']='4';
  dic['J']=dic['K']=dic['L']='5';
  dic['M']=dic['N']=dic['O']='6';
  dic['P']=dic['Q']=dic['R']=dic['S']='7';
  dic['T']=dic['U']=dic['V']='8';
  dic['W']=dic['X']=dic['Y']=dic['Z']='9';
  while(cin>>st){
    string res="";
    for(auto i:st){
	if(dic.find(i)==dic.end())res+=i;
	else res+=dic[i];
    }
    cout<<res<<endl;
  }
  return 0;
}
