#include <bits/stdc++.h>
using namespace std;
int main()
{
 int K;
 scanf("%d\n", &K);
 for(int i =0; i < K; i++)
 {
    int a, b;
    scanf("%d %d\n", &a, &b);
    a--;
    b--;
    int l1 = int((a/3.0)+0.5);
    int l2 = int((b/3.0)+0.5);
    printf("%d\n", (l1*l2));
  }
}
