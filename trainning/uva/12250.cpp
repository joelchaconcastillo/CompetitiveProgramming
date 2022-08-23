#include <bits/stdc++.h>
using namespace std;
int main()
{
  char word[20];
  int cont = 1;
  while(scanf("%s", word), word[0] != '#')
  {
	if( !strcmp( word, "HELLO")) printf("Case %d: ENGLISH\n", cont++);
	else if(!strcmp(word, "HOLA")) printf("Case %d: SPANISH\n", cont++);
	else if(!strcmp(word, "HALLO")) printf("Case %d: GERMAN\n", cont++);
	else if(!strcmp(word, "BONJOUR")) printf("Case %d: FRENCH\n", cont++);
	else if(!strcmp(word, "CIAO")) printf("Case %d: ITALIAN\n", cont++);
	else if(!strcmp(word, "ZDRAVSTVUJTE")) printf("Case %d: RUSSIAN\n", cont++);
	else  printf("Case %d: UNKNOWN\n", cont++);
  }
}
