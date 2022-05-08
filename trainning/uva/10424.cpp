#include <bits/stdc++.h>
#define MAX 30
//#include <iostream>
//#include <cstdio>
using namespace std;
int cleaning(char name1[MAX])
//int cleaning(string name1)
{
    int len1 = strlen(name1), j = 0;
    //int len1 = name1.size(), j = 0;
    int number = 0;
    for(int i = 0; i < len1; i++)
    {
	if( isalpha(name1[i]))
	{
	   name1[j++] = tolower(name1[i]);
	   number += tolower(name1[i])-'a'+1;
	}
    } 
    name1[j] = '\0';
   int v = 0;
   while(number != 0)
   {
	v += (number%10);
	number /=10;
	if( number == 0 && v > 9 ){ number = v; v= 0;}
   }
  return v;
}
int main()
{
  char name1[MAX], name2[MAX];
//  string name1, name2;
//  while( scanf("%s\n%s", name1, name2) != EOF )
 // while( getline(cin, name1) )
  while( fgets(name1, MAX, stdin) != NULL )
  {    
	fgets(name2, MAX, stdin);
	if(feof(stdin)) break;
	if( name2 == NULL ) break;
 //	getline(cin, name2);
	int value1 = cleaning(name1);
	int value2 = cleaning(name2);
	if( value1 < value2) swap(value1, value2);
  	printf("%.2lf %\n", 100.0*((double)value2/value1));
	
  }
  return 0;
}
