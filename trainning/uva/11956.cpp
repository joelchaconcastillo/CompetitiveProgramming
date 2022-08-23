#include <bits/stdc++.h>
using namespace std;
int main()
{
  int T;
  scanf("%d", &T);
  char word[100001];
  int mem[100]={0};
  for(int i = 0; i < T; i++)
  {
    memset(mem, 0, sizeof(int)*100 );
    scanf("%s", word); 
    int pointer = 0, len = strlen(word);
    for(int i = 0;i < len; i++)
    {
      if(word[i] == '+') mem[pointer]=(mem[pointer]+1)%256;
      else if(word[i] == '-') mem[pointer]=(mem[pointer]+255)%256;
      else if(word[i] == '<') pointer = (pointer+99)%100;
      else if(word[i] == '>') pointer = (pointer+1)%100;
    }
    printf("Case %d:" , i+1);
    for(int i = 0; i < 100; i++)
    {
       printf(" %.02X", mem[i]);
    }
    printf("\n");
  }
  return 0;
}
